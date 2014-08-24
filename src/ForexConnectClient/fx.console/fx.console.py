import forexconnect as fx
from _ctypes import *

session = fx.CO2GTransport.createSession()
status = fx.SessionStatusListener(session, False, "", "")

session.subscribeSessionStatus(status);

print status

session.unsubscribeSessionStatus(status)
