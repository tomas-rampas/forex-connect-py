import forexconnect as fx
from multiprocessing import Process, Value, Lock
import win32api

class Counter(object):
    def __init__(self, initval=0):
        self.val = Value('i', initval)
        self.lock = Lock()

    def increment(self):
        with self.lock:
            self.val.value += 1

    def value(self):
        with self.lock:
            return self.val.value

class SessionStatusListener(fx.SessionStatusListener):
    def __init__(self, session):
        super(SessionStatusListener, self). __init__(session, False, "", "")
        self.status = fx.IO2GSessionStatus.Disconnected
    
    def get_status(self):
        return self._status

    def set_status(self, value):
        self._status = value

    status = property(get_status, set_status)

    def printStatus(self):
        print self.status

    def onSessionStatusChanged(self, status):
        super(SessionStatusListener, self).onSessionStatusChanged(status)                
        self.status = status     

    def onLoginFailed(self, error):
        super(SessionStatusListener, self).onLoginFailed(error)

    def hasError(self):
        return super(SessionStatusListener, self).hasError()

    def reset(self):
        return super(SessionStatusListener, self).reset()

    def waitEvents(self):
        return super(SessionStatusListener, self).waitEvents()
        #print self.status

    def isConnected(self):
        return super(SessionStatusListener, self).isConnected()