import forexconnect as fx

class SessionStatusListener(fx.SessionStatusListener):
    def __init__(self, session):
        super(SessionStatusListener, self). __init__(session, False, "", "")

    def onSessionStatusChanged(self, status):
        super(SessionStatusListener, self).onSessionStatusChanged(status)

    def reset(self):
        super(SessionStatusListener, self).reset()