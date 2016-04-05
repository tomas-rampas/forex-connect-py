import time
import forexconnect as fx
from listeners.sessionstatus import *
from listeners.table import TableListener
from settings import ACCOUNT_ID, PWD

def stop():
    tableListener.onOffersChanged -= onDataChanged
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
    while (line not in ('stop', '0')):
        line = raw_input('Prompt ("stop" or "0" to quit): ')
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

def onDataChanged(data):
    #print data.getInstrument()
    print data.getOfferId()

def checkSubscriptions(session, tblManager):    
    offers = tblManager.getTable(fx.O2GTable.Offers)
    offers.__class__ = fx.IO2GOffersTable
    for ii in range(0,10000):
        offer = offers.getRow(ii);
        if not offer: return
        offer.__class__ = fx.IO2GOfferRow
        if offer.getInstrumentType() == 1:
            if offer.getSubscriptionStatus() == "T":
                print offer.getInstrument() + " subscribed"
            else:
                subscribeOffer(session, ii)   
        else:
            print "unsubscribing ", offer.getInstrument()
            unsubscribeOffer(session, ii)

def subscribeOffer(session, offerId):
    valueMap = session.getRequestFactory().createValueMap()
    valueMap.setString(fx.O2GRequestParamsEnum.Command, "SetSubscriptionStatus")#Constants.Commands.SetSubscriptionStatus)
    valueMap.setString(fx.O2GRequestParamsEnum.SubscriptionStatus, "T")
    valueMap.setString(fx.O2GRequestParamsEnum.OfferID, str(offerId))
    factory = session.getRequestFactory()
    request = factory.createOrderRequest(valueMap)
    session.sendRequest(request)

def unsubscribeOffer(session, offerId):
    valueMap = session.getRequestFactory().createValueMap()
    valueMap.setString(fx.O2GRequestParamsEnum.Command, "SetSubscriptionStatus")#Constants.Commands.SetSubscriptionStatus)
    valueMap.setString(fx.O2GRequestParamsEnum.SubscriptionStatus, "D")
    valueMap.setString(fx.O2GRequestParamsEnum.OfferID, str(offerId))
    factory = session.getRequestFactory()
    request = factory.createOrderRequest(valueMap)
    session.sendRequest(request)

def openTrade(session, offerId, accountId, orderRate, amount = 10000):
    valueMap = session.getRequestFactory().createValueMap()
    valueMap.setString(fx.O2GRequestParamsEnum.Command, "CreateOrder"); #Constants.Commands.CreateOrder
    valueMap.setString(fx.O2GRequestParamsEnum.OrderType, "TrueMarketOpen"); #Constants.Orders.TrueMarketOpen
    valueMap.setString(fx.O2GRequestParamsEnum.AccountID, accountId);                     # The identifier of the account the order should be placed for.
    valueMap.setString(fx.O2GRequestParamsEnum.OfferID, offerId);                         # The identifier of the instrument the order should be placed for.
    valueMap.setString(fx.O2GRequestParamsEnum.BuySell, buySell);                         # The order direction (Constants.Buy for buy, Constants.Sell for sell)
    valueMap.setDouble(fx.O2GRequestParamsEnum.Rate, orderRate);                          # The rate at which the order must be filled (below current rate for Buy, above current rate for Sell)
    valueMap.setInt(fx.O2GRequestParamsEnum.Amount, amount);                              # The quantity of the instrument to be bought or sold.
    valueMap.setString(fx.O2GRequestParamsEnum.CustomID, "custom_trade_id");                        # The custom identifier of the order.
    #valueMap.setDouble(fx.O2GRequestParamsEnum.RateStop, stopRate);
    #valueMap.setDouble(fx.O2GRequestParamsEnum.RateLimit, limitRate);
    factory = session.getRequestFactory()
    request = factory.createOrderRequest(valueMap)
    session.sendRequest(request)


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
tableListener.onOffersChanged += onDataChanged
tableManager = session.getTableManager()

if tableManager is not None:
    checkSubscriptions(session, tableManager)

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
        tableListener.printOffers(offers, "")
    except Exception, e:
        print e    

if not status.hasError():
    input_loop()
