import forexconnect as fx

session = fx.CO2GTransport.createSession()
status = fx.SessionStatusListener(session, False, "", "")

session.subscribeSessionStatus(status);

print status

session.unsubscribeSessionStatus(status)
