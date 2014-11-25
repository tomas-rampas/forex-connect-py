import time
import forexconnect as fx
from listeners.sessionstatus import *
from listeners.table import TableListener
from settings import ACCOUNT_ID, PWD

def stop():
    if tableManager is not None and tableListener is not None:
        tableListener.unsubscribeEvents(tableManager)
    if tableListener  is not None:
        tableListener.release()
    session.logout()
    status.waitEvents()
    session.unsubscribeSessionStatus(status)
    session.release()

def input_loop():
    line = ''
    while (line != 'stop'):
        line = raw_input('Prompt ("stop" to quit): ')
        print 'Dispatch %s' % line
    stop()

def getAccount(session):
    readerFactory = session.getResponseReaderFactory()
    if readerFactory is None:
        return None
    loginRules = session.getLoginRules()
    response = loginRules.getTableRefreshResponse(fx.O2GTable.Accounts)
    accountsResponseReader = readerFactory.createAccountsTableReader(response)
    for i in range(accountsResponseReader.size()):
        account = accountsResponseReader.getRow(i)
        if not account.getMaintenanceFlag():
            print account.getBalance()

session = fx.CO2GTransport.createSession()
session.useTableManager(fx.O2GTableManagerMode.Yes, None)
status = SessionStatusListener(session)
session.subscribeSessionStatus(status)
status.reset()

try:
    session.login(ACCOUNT_ID, PWD, "http://www.fxcorporate.com/Hosts.jsp", "Demo")
except Exception, e:
    print repr(e)

if  status.waitEvents() and status.isConnected():
    if status.status == fx.IO2GSessionStatus.Connected:        
        print "ForexConnect client Connected"
        account = getAccount(session)
else:
    stop()

tableListener = TableListener()
tableManager = session.getTableManager()



if tableManager is not None:
    managerStatus = tableManager.getStatus()

    i = 0
    while managerStatus == fx.O2GTableManagerStatus.TablesLoading:
        time.sleep(0.250)
        i += 1
        if not i % 10 : print tableManager.getStatus()
        managerStatus = tableManager.getStatus()    

    if managerStatus == fx.O2GTableManagerStatus.TablesLoadFailed:
        print "Cannot refresh all tables of table manager"

    tableListener.setInstrument("GER30")
    tableListener.subscribeEvents(tableManager)
    offers = tableManager.getTable(fx.O2GTable.Offers)
    try:
        offers.__class__ = fx.IO2GOffersTable
        #tableListener.printOffers(offers, "")
        pass
    except Exception, e:
        print e    




if not status.hasError():
    input_loop()
