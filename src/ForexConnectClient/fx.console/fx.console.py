import forexconnect as fx
from settings import ACCOUNT_ID, PWD

class SessionStatusListenerPy(fx.SessionStatusListener):
    def __init__(self, session):
        super(SessionStatusListenerPy, self). __init__(session, False, "", "")

    def onSessionStatusChanged(self, status):
        print "from py " 
        super(SessionStatusListenerPy, self).onSessionStatusChanged(status)

    def reset(self):
        print "py:reset"
        super(SessionStatusListenerPy, self).reset()

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
#status = fx.SessionStatusListener(session, False, "", "")
status = SessionStatusListenerPy(session)

session.subscribeSessionStatus(status);
status.reset()
session.login(ACCOUNT_ID, PWD, "http://www.fxcorporate.com/Hosts.jsp", "Demo")

if status.waitEvents() and status.isConnected():
    print "ForexConnect client Connected"
    account = getAccount(session)

def stop():
    session.logout();
    status.waitEvents();
    session.unsubscribeSessionStatus(status)

def input_loop():
    line = ''
    while line != 'stop':
        line = raw_input('Prompt ("stop" to quit): ')
        print 'Dispatch %s' % line
    stop()

input_loop()


