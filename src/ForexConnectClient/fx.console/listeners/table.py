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
        pass

    def onChanged(self, rowID, row):
        if row.getTableType() == fx.O2GTable.Offers:
            printOffer(row, self.instrument)

    def onDelete(self, rowID, row):
        pass

    def onStatusChanged(self, rowID, row):
        pass

    def printOffers(self, offersTable, instrument):
        offerRow = None
        iterator = fx.IO2GTableIterator()
        #while offersTable.getNextRow(iterator, offerRow):
        offersTable.getNextRow(iterator, offerRow)
        printOffer(offerRow, instrument)
        offerRow.release()

    def printOffer(self, offerRow, instrument):
        print offerRow.getOfferID()

    def subscribeEvents(self,manager):
        offersTable = manager.getTable(fx.O2GTable.Offers)
        offersTable.__class__ = fx.IO2GOffersTable
        print offersTable.__class__
        print offersTable.getRow(0)
        #offersTable.subscribeUpdate(fx.O2GTableUpdateType.Update, self)

    def unsubscribeEvents(self, manager):
        offersTable = manager.getTable(fx.O2GTable.Offers)
        offersTable.unsubscribeUpdate(fx.O2GTableUpdateType.Update, self)
