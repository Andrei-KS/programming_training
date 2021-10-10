#include "Turnstile.h"

bool Turnstile::isLocked = true;
bool Turnstile::isAlarming = false;
int Turnstile::itsCoins = 0;
int Turnstile::itsRefunds = 0;

Turnstile* Turnstile::LOCKED = new Locked();
Turnstile* Turnstile::UNLOCKED = new UnLocked();
Turnstile* Turnstile::itsState = LOCKED;

void Turnstile::lock(bool shouldLock)
{
	isLocked = shouldLock;
}

void Turnstile::alarm(bool shouldAlarm)
{
	isAlarming = shouldAlarm;
}

void Turnstile::reset()
{
	lock(true);
	alarm(false);
	itsCoins = 0;
	itsRefunds = 0;
	itsState = LOCKED;
}

bool Turnstile::locked()
{
	return isLocked;
}

bool Turnstile::alarm()
{
	return isAlarming;
}

void Turnstile::coin()
{
	itsState->coin();
}

void Turnstile::pass()
{
	itsState->pass();
}

int Turnstile::coins()
{
	return itsCoins;
}

int Turnstile::refunds()
{
	return itsRefunds;
}

void Turnstile::deposit()
{
	itsCoins++;
}

void Turnstile::refund()
{
	itsRefunds++;
}

void Locked::coin()
{
	itsState = UNLOCKED;
	lock(false);
	alarm(false);
	deposit();
}

void Locked::pass()
{
	alarm(true);
}

void UnLocked::coin()
{
	refund();
}

void UnLocked::pass()
{
	lock(true);
	itsState = LOCKED;
}
