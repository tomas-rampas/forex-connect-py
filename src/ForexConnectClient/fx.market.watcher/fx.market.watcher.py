import os, sys
import tkFont, ttk, tkMessageBox
from Tkinter import *
#from ttk import Frame, Button, Style
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
('EUR/CHF', '0.000000', '0.000000') ,
('AUD/NZD', '0.000000', '0.000000') ,
('GBP/JPY', '0.000000', '0.000000') ,
('GER30', '0.000000', '0.000000') ,]

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
            self.tree.insert('', 'end', values=item)
            # adjust column's width if necessary to fit each value
            for ix, val in enumerate(item):
                col_w = tkFont.Font().measure(val)
                if self.tree.column(symbols_header[ix],width=None)<col_w:
                    self.tree.column(symbols_header[ix], width=col_w)

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
        self.session = None
        self.status = None        
        self.parent = parent
        self.status = None
        self.initUI()
        
    def initUI(self):
      
        self.parent.title(window_caption)
        self.style = ttk.Style()
        self.style.theme_use("default")

        frame = Frame(self, relief=RAISED, borderwidth=1)
        symbolList = MultiColumnListBox(frame)
        symbolList.pack()
        frame.pack(fill=BOTH, expand=1)
        self.logger = Text(frame, height=10)
        self.logger.pack()
        self.pack(fill=BOTH, expand=1)
        
        closeButton = ttk.Button(self, text="Close", command = lambda: self.close_window(), underline=0)        
        closeButton.pack(side=RIGHT, padx=5, pady=5)
        self.parent.bind('<Alt_L><c>', lambda e:closeButton.invoke())
        logoutButton = ttk.Button(self, text="Logout", command = lambda: self.logout(), underline=3)
        logoutButton.pack(side=RIGHT)
        self.parent.bind('<Alt_L><o>', lambda e:logoutButton.invoke())
        loginButton = ttk.Button(self, text="Login", command = lambda: self.login(),underline=3)
        loginButton.pack(side=RIGHT)
        self.parent.bind('<Alt_L><i>', lambda e:loginButton.invoke())
         
        menubar = Menu(self)
        filemenu = Menu(menubar, tearoff=0)
        filemenu.add_command(label="Login", command=self.login, underline=0)
        filemenu.add_command(label="Logout", command=self.logout, accelerator='Ctrl-O')
        filemenu.add_separator()
        filemenu.add_command(label="Exit", command=self.close_window, accelerator='Ctrl-X', underline=1)
        menubar.add_cascade(label="File", menu=filemenu)
        self.master.config(menu=menubar)
        #self.master.bind_all("<Control-x>", self.close_window)
        self.parent.bind("<Control-l>", self.login)

    def close_window (self):
        if self.status and self.status.isConnected():
            tkMessageBox.showwarning(window_caption, "ForexConnect client Connected! Disconnect first")
        else:
            self.parent.destroy() 
    
    def login(self):    
        self.session = fx.CO2GTransport.createSession()
        self.status = SessionStatusListener(self.session)
        self.session.subscribeSessionStatus(self.status);
        self.status.reset()

        try:
            self.session.login(ACCOUNT_ID, PWD, "http://www.fxcorporate.com/Hosts.jsp", "Demo")
        except Exception, e:
            print repr(e)

        if self.status.waitEvents() and self.status.isConnected():
            #if self.status.status == fx.IO2GSessionStatus.Connected:
            #tkMessageBox.showinfo("fxClient", "ForexConnect client Connected")
            self.log("ForexConnect client Connected")
            #self.account = getAccount(self.session) 
            self.createTableListener()

    def logout(self):
        if self.session is not None:
            self.session.logout()
            self.status.waitEvents()
            self.session.unsubscribeSessionStatus(self.status)
            self.log("ForexConnect client Disconnected")
            #tkMessageBox.showinfo("fxClient", "ForexConnect client Disconnected")

    def createTableListener(self):
        self.tableListener = TableListener()
        self.tableManager = self.session.getTableManager()

        if self.tableManager is not None:
            managerStatus = self.tableManager.getStatus()

            i = 0
            while managerStatus == fx.O2GTableManagerStatus.TablesLoading:
                time.sleep(0.250)
                i += 1
                if not i % 10 : self.log(self.tableManager.getStatus())
                managerStatus = self.tableManager.getStatus()    

            if managerStatus == fx.O2GTableManagerStatus.TablesLoadFailed:
                self.log("Cannot refresh all tables of table manager")

            self.tableListener.setInstrument("GER30")
            self.tableListener.subscribeEvents(tableManager)
            offers = self.tableManager.getTable(fx.O2GTable.Offers)
            try:
                offers.__class__ = fx.IO2GOffersTable
                #self.log(self.tableListener.printOffers(offers, ""))
            except Exception, e:
                print e    

    def log(self, message):
        if self.logger:
            self.logger.insert(END, message + "\n")


def main():
  
    root = Tk()
    root.geometry("600x450+200+200")
    app = MarketWatcher(root)
    root.protocol("WM_DELETE_WINDOW", app.close_window)
    root.bind('<Escape>', lambda e: root.iconify)
    root.bind("<Control-x>", 'exit')
    root.bind("<Control-q>", 'exit')
    root.mainloop()  


if __name__ == '__main__':
    main()  
