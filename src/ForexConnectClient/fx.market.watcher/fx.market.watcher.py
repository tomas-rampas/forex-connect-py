import os, sys, time, threading, Queue
import tkFont, ttk, tkMessageBox
from dialogs.order import OpenPosition
from Tkinter import *
import forexconnect as fx

scriptpath = "../fx.console/listeners/"
sys.path.append(os.path.abspath(scriptpath))
scriptpath = "../fx.console/"
sys.path.append(os.path.abspath(scriptpath))
from sessionstatus import SessionStatusListener
from table import TableListener

window_caption = "MarketWatcher"
try:
    from settings import ACCOUNT_ID, PWD
except BaseException:
    tkMessageBox.showinfo(window_caption, "Create settings.py with ACCOUNT_ID and PWD")
    sys.exit(0)

symbols_header = ['Symbol', 'Bid', 'Ask']
symbols_list = [
    ('EUR/USD', '0.000000', '0.000000') ,
    ('EUR/CHF', '0.000000', '0.000000') ,
    ('USD/JPY', '0.000000', '0.000000') ,
    ('GBP/USD', '0.000000', '0.000000') ,
    ('AUD/USD', '0.000000', '0.000000') ,
    ('NZD/USD', '0.000000', '0.000000') ,
    ('EUR/NZD', '0.000000', '0.000000') ,
    ('AUD/NZD', '0.000000', '0.000000') ,
    ('GBP/JPY', '0.000000', '0.000000') ,
    ('XAU/USD', '0.000000', '0.000000') ,
    ('GER30', '0.000000', '0.000000') ,
]

class Test(Toplevel):
    def __init__(self, parent, title = None):
        Toplevel.__init__(self, parent)
        self.transient(parent)

        if title:
            self.title(title)

        self.parent = parent
        self.result = None
        body = Frame(self)
        self.initial_focus = self.body(body)
        body.pack(padx=5, pady=5)
        self.buttonbox()
        self.grab_set()
        if not self.initial_focus:
            self.initial_focus = self

        self.protocol("WM_DELETE_WINDOW", self.cancel)
        self.geometry("+%d+%d" % (parent.winfo_rootx()+50,
                                  parent.winfo_rooty()+50))
        self.initial_focus.focus_set()
        self.wait_window(self)

    #
    # construction hooks
    def body(self, master):
        # create dialog body.  return widget that should have
        # initial focus.  this method should be overridden
        pass

    def buttonbox(self):
        # add standard button box. override if you don't want the
        # standard buttons
        box = Frame(self)
        w = Button(box, text="OK", width=10, command=self.ok, default=ACTIVE)
        w.pack(side=LEFT, padx=5, pady=5)
        w = Button(box, text="Cancel", width=10, command=self.cancel)
        w.pack(side=LEFT, padx=5, pady=5)
        self.bind("<Return>", self.ok)
        self.bind("<Escape>", self.cancel)

        box.pack()

    #
    # standard button semantics
    def ok(self, event=None):

        if not self.validate():
            self.initial_focus.focus_set() # put focus back
            return
        self.withdraw()
        self.update_idletasks()
        self.apply()
        self.cancel()

    def cancel(self, event=None):
        # put focus back to the parent window
        self.parent.focus_set()
        self.destroy()

    #
    # command hooks

    def validate(self):
        return 1 # override

    def apply(self):
        pass # override

class Offer(object):
    def __init__(self, instrument = None, bid = 0.0, ask = 0.0, volume = 0, digits = 5):
        self._instrument = instrument
        self._bid = bid
        self._ask = ask
        self._volume = volume
        self._digits = digits

    def __str__(self):
        return "{ins}, bid:{bid:.{dec}f}, ask:{ask:.{dec}f}, volume:{vol}, digits:{dec}".format(ins=self._instrument, bid=self._bid, ask=self._ask,
                                                                                               vol=self._volume, dec=self._digits)

    @property
    def instrument(self):
        return self._instrument

    @instrument.setter
    def instrument(self, value):
        self._instrument = value

    @property
    def bid(self):
        return self._bid

    @bid.setter
    def bid(self, value):
        self._bid = value

    @property
    def ask(self):
        return self._ask

    @ask.setter
    def ask(self, value):
        self._ask = value

    @property
    def digits(self):
        return self._digits

    @digits.setter
    def digits(self, value):
        self._digits = value

class MultiColumnListBox(Frame):

    def __init__(self, parent):
        Frame.__init__(self, parent)           
        self.parent = parent
        self.tree = None
        self._setup_widgets()
        self._build_tree()

    def _setup_widgets(self):
        container = ttk.Frame()
        container.pack(fill='both', expand=True)
        # create a treeview with dual scrollbars
        self.tree = ttk.Treeview(columns=symbols_header, show="headings")
        vsb = ttk.Scrollbar(orient="vertical", command=self.tree.yview)
        hsb = ttk.Scrollbar(orient="horizontal", command=self.tree.xview)
        self.tree.configure(yscrollcommand=vsb.set, xscrollcommand=hsb.set)
        self.tree.grid(column=0, row=0, sticky='nsew', in_=container)
        vsb.grid(column=1, row=0, sticky='ns', in_=container)
        hsb.grid(column=0, row=1, sticky='ew', in_=container)
        container.grid_columnconfigure(0, weight=1)
        container.grid_rowconfigure(0, weight=1)

    def _build_tree(self):
        for col in symbols_header:
            self.tree.heading(col, text=col.title(), command=lambda c=col: sortby(self.tree, c, 0))
            # adjust the column's width to the header string
            self.tree.column(col, width=tkFont.Font().measure(col.title()))
        for item in symbols_list:
            self.tree.insert('', 'end', iid=item[0], values=item)
            # adjust column's width if necessary to fit each value
            for ix, val in enumerate(item):
                col_w = tkFont.Font().measure(val)
                if self.tree.column(symbols_header[ix],width=None) < col_w:
                    self.tree.column(symbols_header[ix], width=col_w)

    def updateValues(self, offer):        
        #self.tree.item(symbol, values = [symbol, bid, ask])
        if self.tree.exists(offer.instrument):
            #self.tree.focus(offer.instrument)
            #self.tree.selection_set(offer.instrument)
            self.tree.item(offer.instrument, values = [
                offer.instrument, 
                "{bid:.{dec}f}".format(bid=offer.bid, dec=offer.digits), 
                "{ask:.{dec}f}".format(ask=offer.ask, dec=offer.digits),
            ])
            #time.sleep(0.05)
            #self.tree.selection_remove(offer.instrument)


def sortby(tree, col, descending):
    """
    sort tree contents when a column header is clicked on
    grab values to sort
    """
    data = [(tree.set(child, col), child) \
        for child in tree.get_children('')]
    # if the data to be sorted is numeric change to float
    #data = change_numeric(data)
    # now sort the data in place
    data.sort(reverse=descending)
    for ix, item in enumerate(data):
        tree.move(item[1], '', ix)
    # switch the heading so it will sort in the opposite direction
    tree.heading(col, command=lambda col=col: sortby(tree, col, int(not descending)))

class MarketWatcher(ttk.Frame):
  
    def __init__(self, parent):
        ttk.Frame.__init__(self, parent)           
        self.lock = threading.Lock()
        self.symbolList = None
        self.session = None
        self.tableManager = None
        self.tableListener = None
        self.status = None  
        self.account = None      
        self.offers = None
        self.parent = parent
        self.queue = Queue.Queue()
        self.initUI()
        
    def initUI(self):
      
        self.parent.title(window_caption)
        self.style = ttk.Style()
        self.style.theme_use("default")

        self.frame = Frame(self, relief=RAISED, borderwidth=1)
        self.symbolList = MultiColumnListBox(self.frame)
        self.symbolList.pack()
        self.frame.pack(fill=BOTH, expand=1)
        self.logger = Text(self.frame, height=10)
        self.logger.grid()
        self.scroller = Scrollbar(self.frame,command=self.logger.yview)
        self.logger.config(yscrollcommand=self.scroller.set)
        self.scroller.pack(side="right", fill="y", expand=False)
        self.logger.pack()
        self.pack(fill=BOTH, expand=1)
        
        closeButton = ttk.Button(self, text="Exit", command = lambda: self.close_window(), underline=0)        
        closeButton.pack(side=RIGHT, padx=5, pady=5)
        self.parent.bind('<Alt_L><e>', lambda e:closeButton.invoke())
        logoutButton = ttk.Button(self, text="Logout", command = lambda: self.logout(), underline=3)
        logoutButton.pack(side=RIGHT)
        self.parent.bind('<Alt_L><o>', lambda e:logoutButton.invoke())
        loginButton = ttk.Button(self, text="Login", command = lambda: self.login(),underline=3)
        loginButton.pack(side=RIGHT)
        self.parent.bind('<Alt_L><i>', lambda e:loginButton.invoke())
        openButton = ttk.Button(self, text="Open", command = lambda: self.openPosition())
        openButton.pack(side=LEFT)
        closeButton = ttk.Button(self, text="Close", command = lambda: self.closePosition())
        closeButton.pack(side=LEFT)
         
        menubar = Menu(self)
        filemenu = Menu(menubar, tearoff=0)
        filemenu.add_command(label="Login", command=self.login, underline=0)
        filemenu.add_command(label="Logout", command=self.logout, accelerator='Ctrl-O')
        filemenu.add_separator()
        filemenu.add_command(label="Orders", command=self.getOrders)
        filemenu.add_command(label="Trades", command=self.getTrades)
        filemenu.add_separator()
        filemenu.add_command(label="Exit", command=self.close_window, accelerator='Ctrl-X', underline=1)
        menubar.add_cascade(label="File", menu=filemenu)
        self.master.config(menu=menubar)
        #self.master.bind_all("<Control-x>", self.close_window)
        self.parent.bind("<Control-l>", self.login)

    def write(self, str):
        self.log(str)

    def close_window(self):
        if self.status and self.status.isConnected():
            tkMessageBox.showwarning(window_caption, "ForexConnect client Connected! Disconnect first")
        else:
            self.parent.destroy() 
    
    def login(self):            
        self.session = fx.CO2GTransport.createSession()
        self.session.useTableManager(fx.O2GTableManagerMode.Yes, None)
        self.status = SessionStatusListener(self.session)
        self.session.subscribeSessionStatus(self.status)
        self.status.reset()

        try:
            self.session.login(ACCOUNT_ID, PWD, "http://www.fxcorporate.com/Hosts.jsp", "Demo")

            if self.status.waitEvents() and self.status.isConnected():
                if self.status.status == fx.IO2GSessionStatus.Connected:
                    self.log("ForexConnect client Connected")
                self.account = self.getAccount()
                self.createTableListener()
        except Exception, e:
            print repr(e)

    def getAccount(self):
        readerFactory = self.session.getResponseReaderFactory()
        if readerFactory is None:
            return None
        loginRules = self.session.getLoginRules()
        response = loginRules.getTableRefreshResponse(fx.O2GTable.Accounts)
        accountsResponseReader = readerFactory.createAccountsTableReader(response)
        for i in range(accountsResponseReader.size()):
            account = accountsResponseReader.getRow(i)
            if not account.getMaintenanceFlag():        
                self.log("Current account balance:" + str(account.getBalance()))


    def getOrders(self):
        orders = self.tableManager.getTable(fx.O2GTable.Orders)
        orders.__class__ = fx.IO2GOrdersTable
        for i in range(orders.size()):
            order = orders.getRow(i)
            order.__class__ = fx.IO2GOrderRow
            if self.offers:
                offer = self.offers.findRow(str(order.getOfferID()))
                if offer:
                    offer.__class__ = fx.IO2GOfferRow
            self.log("%s %s %d" % (order.getBuySell(), offer.getInstrument(), order.getAmount()))

    def getTrades(self):
        trades = self.tableManager.getTable(fx.O2GTable.Trades)
        trades.__class__ = fx.IO2GTradesTable
        for i in range(trades.size()):
            trade = trades.getRow(i)
            trade.__class__ = fx.IO2GTradeTableRow
            if self.offers:
                offer = self.offers.findRow(str(trade.getOfferID()))
                if offer:
                    offer.__class__ = fx.IO2GOfferRow
            self.log("%s %s %d %f %f %f" % (trade.getBuySell(), offer.getInstrument(), trade.getAmount() ,trade.getOpenRate(), trade.getLimit(), trade.getStop()))

    def openPosition(self):
        openDialog = OpenPosition(self.parent)
        result = openDialog.result
        print result

    def editPosition(self):
        openDialog = OpenPosition(self.parent)
        result = openDialog.result
        print result

    def closePosition(self):
        tkMessageBox.showinfo(window_caption, "TBD: Close Position")

    def logout(self):        
        if self.tableManager is not None and self.tableListener is not None:
            self.tableListener.unsubscribeEvents(self.tableManager)
        if self.tableListener is not None:
            self.tableListener.onOffersChanged -= self.onOffersChanged
            self.tableListener.release()

        if self.session is not None:
            if self.session.getSessionStatus() == fx.IO2GSessionStatus.Connected:
                self.session.logout()
                self.status.waitEvents()
            self.session.unsubscribeSessionStatus(self.status)
            print "ForexConnect client Disconnected"

    def createTableListener(self):        
        self.tableListener = TableListener()
        self.tableManager = self.session.getTableManager()
        if self.tableManager:
            managerStatus = self.tableManager.getStatus()

            i = 0
            while managerStatus == fx.O2GTableManagerStatus.TablesLoading:
                time.sleep(0.050)
                i += 1
                if not i % 500 : print self.tableManager.getStatus()
                managerStatus = self.tableManager.getStatus()    

            if managerStatus == fx.O2GTableManagerStatus.TablesLoadFailed:
                self.log("Cannot refresh all tables of table manager")

            self.tableListener.setInstrument("GER30")
            self.tableListener.subscribeEvents(self.tableManager)
            self.offers = self.tableManager.getTable(fx.O2GTable.Offers)
            self.initOffers(self.offers)
            self.tableListener.onOffersChanged += self.onOffersChanged
            self.periodicCall()
            
    def initOffers(self, offersTable):
        offersTable.__class__ = fx.IO2GOffersTable
        iterator = fx.IO2GTableIterator()
        offerRow = offersTable.getNextRow(iterator)
        while offerRow:
            self.symbolList.updateValues(Offer(offerRow.getInstrument(), offerRow.getBid(), offerRow.getAsk(), offerRow.getVolume(), offerRow.getDigits()))
            offerRow.release()
            offerRow = offersTable.getNextRow(iterator)
            
    def onOffersChanged(self, offerRow):        
        self.queue.put(Offer(offerRow.getInstrument(), offerRow.getBid(), offerRow.getAsk(), offerRow.getVolume(), offerRow.getDigits()))

    def processIncoming(self):
        while self.queue.qsize():
            try:
                offer = self.queue.get(0)
                #print offer
                self.symbolList.updateValues(offer)
            except Queue.Empty:
                pass

    def periodicCall(self):
        self.processIncoming()
        self.parent.after(50, self.periodicCall)

    def log(self, message):
        if self.logger:
            if message[-1] == '\n':
                message = message[:-1]
            if len(message) > 0:
                self.logger.insert(END, message + "\n")
                self.logger.see(END)


def main():
  
    root = Tk()
    root.geometry("600x450+200+200")
    app = MarketWatcher(root)
    sys.stdout = app
    root.protocol("WM_DELETE_WINDOW", app.close_window)
    root.bind('<Escape>', lambda e: root.iconify)
    root.bind("<Control-x>", 'exit')
    root.bind("<Control-q>", 'exit')
    root.mainloop()      

if __name__ == '__main__':
    main()  
