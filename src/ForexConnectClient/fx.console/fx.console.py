import forexconnect as fx
from _ctypes import *

class SessionStatusListener(fx.IO2GSessionStatus):
    def __init__(self, session, printSubsessions, sessionID, pin):
        self.session = session
        self.printSubsessions = printSubsessions
        self.sessionID = sessionID
        self.pin = pin
        session.addRef()

    def __del__(self):
        session.release()
    
    def onSessionStatusChanged(self):
        pass
    def onLoginFailed(self):
        pass

session = fx.CO2GTransport.createSession()
status = SessionStatusListener(session, False, "", "")

session.subscribeSessionStatus(status)

print status

session.unsubscribeSessionStatus(status)
