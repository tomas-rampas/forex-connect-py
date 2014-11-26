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

class EventHook(object):
    def __init__(self):
        self.__handlers = []

    def __iadd__(self, handler):
        self.__handlers.append(handler)
        return self

    def __isub__(self, handler):
        self.__handlers.remove(handler)
        return self

    def fire(self, *args, **keywargs):
        for handler in self.__handlers:
            handler(*args, **keywargs)

    def clearObjectHandlers(self, inObject):
        self.__handlers = [h for h in self.__handlers if h.im_self != obj]
        for theHandler in self.__handlers:
            if theHandler.im_self == inObject:
                self -= theHandler