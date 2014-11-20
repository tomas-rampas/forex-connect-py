import forexconnect as fx
from sessionstatus import Counter

class TableListener(fx.IO2GTableListener):
    def __init__(self):
        self.refcount = Counter(1)