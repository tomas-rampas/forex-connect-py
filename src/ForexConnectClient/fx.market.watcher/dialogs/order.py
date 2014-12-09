from Tkinter import *
import tkMessageBox
import os

class OrderDialog(Toplevel):

    def __init__(self, parent, title=None):
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
        self.geometry("+%d+%d" % (parent.winfo_rootx() + 50,
                                  parent.winfo_rooty() + 50))
        self.initial_focus.focus_set()
        self.wait_window(self)

    def body(self, master):
        pass

    def buttonbox(self):
        box = Frame(self)
        w = Button(box, text="OK", width=10, command=self.ok, default=ACTIVE)
        w.pack(side=LEFT, padx=5, pady=5)
        w = Button(box, text="Cancel", width=10, command=self.cancel)
        w.pack(side=LEFT, padx=5, pady=5)
        self.bind("<Return>", self.ok)
        self.bind("<Escape>", self.cancel)
        box.pack()

    def ok(self, event=None):

        if not self.validate():
            self.initial_focus.focus_set()
            return
        self.withdraw()
        self.update_idletasks()
        self.apply()
        self.cancel()

    def cancel(self, event=None):
        self.parent.focus_set()
        self.destroy()

    def validate(self):
        return 1

    def apply(self):
        pass

class OpenPosition(OrderDialog):
    """description of class"""
    def __init__(self, parent, order=None, title=None):
        OrderDialog.__init__(self, parent, title)
        self.order = order

    def body(self, master):
        Label(master, text="Pair:").grid(row=0, sticky=W)
        Label(master, text="Amount:").grid(row=1, sticky=W)
        Label(master, text="Take Profit:").grid(row=2, sticky=W)
        Label(master, text="Stop Loss:").grid(row=3, sticky=W)

        self.e1 = Entry(master)
        self.e2 = Entry(master)
        self.e1.grid(row=0, column=1)
        self.e2.grid(row=1, column=1)
        self.tp = Entry(master)
        self.tp.grid(row=2, column=1)
        self.sl = Entry(master)
        self.sl.grid(row=3, column=1)

    def apply(self):
        try:
            pair = self.e1.get()
            amount = int(self.e2.get())
            tp = float(self.tp.get())            
            sl = float(self.sl.get())
            self.result = {'pair': pair, 'amount': amount, 'tp': tp, 'sl': sl }
        except ValueError:
            tkMessageBox.showwarning("Bad input","Illegal values, please try again")

class ClosePosition(OrderDialog):
    """description of class"""


