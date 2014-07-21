#pragma once
#include "forex.connect.h"
#include <IO2GSession.h>


class SessionStatusListener : public IO2GSessionStatus
{
public:
	SessionStatusListener();
	~SessionStatusListener();
	void onSessionStatusChanged(O2GSessionStatus status);
	void onLoginFailed(const char *error);

};

