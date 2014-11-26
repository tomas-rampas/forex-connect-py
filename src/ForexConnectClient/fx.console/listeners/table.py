import forexconnect as fx
from sessionstatus import Counter

class TableListener(fx.TableListener):
    def __init__(self):
        super(TableListener, self).__init__()
        self.refcount = Counter(1)
        self.instrument = ""
        self.offers = []

    def __del__(self):
        pass

    def addRef(self):
        self.refcount.increment()
        ref = self.refcount.value
        return ref

    def release(self):
        self.refcount.decrement()
        ref = self.refcount.value
        if self.refcount.value == 0:
            del self
        return ref

    def setInstrument(self, instrument):
        self.instrument = instrument

    def onAdded(self, rowID, row):
        print "onAdded"

    def onChanged(self, rowID, row):
        print "onChanged1"
        if row.getTableType() == fx.O2GTable.Offers:
            printOffer(row, self.instrument)

    def onDelete(self, rowID, row):
        print "onDelete"

    def onStatusChanged(self, status):
        print status

    def printOffers(self, offersTable, instrument):
        iterator = fx.IO2GTableIterator()
        offerRow = offersTable.getNextRow(iterator)
        while offerRow:
            self.printOffer(offerRow, instrument)
            offerRow.release()
            offerRow = offersTable.getNextRow(iterator)

    def printOffer(self, offerRow, instrument):
        print offerRow.getInstrument()

    def subscribeEvents(self,manager):
        offersTable = manager.getTable(fx.O2GTable.Offers)
        offersTable.__class__ = fx.IO2GOffersTable
        offersTable.subscribeUpdate(fx.O2GTableUpdateType.Update, self)

    def unsubscribeEvents(self, manager):
        offersTable = manager.getTable(fx.O2GTable.Offers)
        offersTable.__class__ = fx.IO2GOffersTable
        offersTable.unsubscribeUpdate(fx.O2GTableUpdateType.Update, self)
