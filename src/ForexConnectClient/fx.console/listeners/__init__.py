__all__ = ["sessionstatus", "table"]

from multiprocessing import Process, Value, Lock

class Counter(object):
    def __init__(self, initval=0):
        self.val = Value('i', initval)
        self.lock = Lock()

    def increment(self, n = 1):
        with self.lock:
            self.val.value += n        

    def decrement(self, n = 1):
        with self.lock:
            self.val.value -= n        

    @property
    def value(self):
        with self.lock:
            return self.val.value
