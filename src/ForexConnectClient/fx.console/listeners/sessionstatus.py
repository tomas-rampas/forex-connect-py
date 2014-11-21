import forexconnect as fx
from win32api import CloseHandle
from win32event import CreateEvent, SetEvent, WaitForSingleObject, WAIT_OBJECT_0
from listeners import Counter

class SessionStatusListener(fx.SessionStatusListener):
    def __init__(self, session):
        super(SessionStatusListener, self). __init__()
        self.reset()
        self.sessionId = ""
        self.pin = ""
        self.refcount = Counter(1)
        self.status = fx.IO2GSessionStatus.Disconnected
        self.session = session
        self.session.addRef()
        self.event = CreateEvent(None, 0, 0, None);

    def __del__(self):
        self.session.release()
        CloseHandle(self.event)

    def get_status(self):
        return self._status

    def set_status(self, value):
        self._status = value

    status = property(get_status, set_status)
    
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

    def printStatus(self):
        print self.status

    def onSessionStatusChanged(self, status):
        print status
        self.status = status
        if self.status == fx.IO2GSessionStatus.Disconnected:
            self.connected = False
            SetEvent(self.event)
        elif self.status == fx.IO2GSessionStatus.Connecting:
            pass
        elif self.status == fx.IO2GSessionStatus.TradingSessionRequested:
            descriptors = session.getTradingSessionDescriptors();
            found = False
            if descriptors is not None:
                for i in range(descriptors.size()):
                    desc = descriptors.get(i)
                    print " id:='", desc.getID(), "' name='", desc.getName(), "' description='", desc.getDescription(), "'"
                    if self.sessionId == desc.getID:
                        found = True
                        break

            if found:
                session.setTradingSession(self.sessionId, self.pin )
                pass
            else:
                pass
        elif self.status == fx.IO2GSessionStatus.Connected:
            self.connected = True
            SetEvent(self.event)
        elif self.status == fx.IO2GSessionStatus.Reconnecting:            
            pass
        elif self.status == fx.IO2GSessionStatus.Disconnecting:
            pass
        elif self.status == fx.IO2GSessionStatus.SessionLost:
            pass        

    def onLoginFailed(self, error):
        print "Login error %s" % (error)
        self.error = True

    def reset(self):
        self.connected = False
        self.error = False

    def hasError(self):
        return self.error

    def waitEvents(self):
        return (WaitForSingleObject(self.event, 30000) == WAIT_OBJECT_0)

    def isConnected(self):
        return self.connected