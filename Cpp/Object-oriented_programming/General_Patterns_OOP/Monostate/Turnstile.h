#ifndef __TURNSTILE__
#define	__TURNSTILE__

class Turnstile
{
private:
	static bool isLocked;
	static bool isAlarming;
	static int itsCoins;
	static int itsRefunds;

protected:
	static Turnstile* LOCKED;
	static Turnstile* UNLOCKED;
	static Turnstile* itsState;

protected:
	virtual void lock(bool shouldLock);
	virtual void alarm(bool shouldAlarm);

public:
	virtual void reset();
	virtual bool locked();
	virtual bool alarm();
	virtual void coin();
	virtual void pass();
	virtual int coins();
	virtual int refunds();
	virtual void deposit();
	virtual void refund();
};

class Locked : public Turnstile
{
public:
	void coin() override;
	void pass() override;
};

class UnLocked : public Turnstile
{
	void coin() override;
	void pass() override;
};

#endif