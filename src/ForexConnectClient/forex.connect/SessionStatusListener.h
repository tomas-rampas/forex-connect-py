#pragma once

class SessionStatusListener : public IO2GSessionStatus
{
public:
	virtual void onSessionStatusChanged(O2GSessionStatus status) = 0;
	virtual void onLoginFailed(const char* error) = 0;
};
