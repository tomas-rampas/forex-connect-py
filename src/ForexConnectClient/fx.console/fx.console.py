import forexconnect as fx
from listeners.sessionstatus import *
from settings import ACCOUNT_ID, PWD

def stop():
    session.logout();
    status.waitEvents();
    session.unsubscribeSessionStatus(status)

def input_loop():
    line = ''
    while (line != 'stop'):
        line = raw_input('Prompt ("stop" to quit): ')
        print 'Dispatch %s' % line
    stop()

def getAccount(session):
    readerFactory = session.getResponseReaderFactory();
    if readerFactory is None:
        return None
    loginRules = session.getLoginRules()
    response = loginRules.getTableRefreshResponse(fx.O2GTable.Accounts);
    accountsResponseReader = readerFactory.createAccountsTableReader(response);
    for i in range(accountsResponseReader.size()):
        account = accountsResponseReader.getRow(i);
        if not account.getMaintenanceFlag():
            print account.getBalance()

session = fx.CO2GTransport.createSession()

status = SessionStatusListener(session)
session.subscribeSessionStatus(status);
status.reset()

try:
    session.login(ACCOUNT_ID, PWD, "http://www.fxcorporate.com/Hosts.jsp", "Demo")
except Exception, e:
    print repr(e)

if status.waitEvents() and status.isConnected():
    if status.status == fx.IO2GSessionStatus.Connected:
        print "ForexConnect client Connected"
        account = getAccount(session)
else:
    stop()

if not status.hasError():
    input_loop()


