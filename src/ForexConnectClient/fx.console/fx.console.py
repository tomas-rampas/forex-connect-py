import forexconnect as fx
from settings import ACCOUNT, PWD

session = fx.CO2GTransport.createSession()
status = fx.SessionStatusListener(session, False, "", "")

session.subscribeSessionStatus(status);

session.login(ACCOUNT, PWD, "http://www.fxcorporate.com/Hosts.jsp", "Demo")

if status.waitEvents() and status.isConnected():
    print "ForexConnect client Connected"
    session.logout();
    status.waitEvents();


session.unsubscribeSessionStatus(status)

