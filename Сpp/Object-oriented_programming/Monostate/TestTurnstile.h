#ifndef __TEST_TURNSTILE__
#define __TEST_TURNSTILE__

#include "Turnstile.h"

class TestTurnstile
{
	Turnstile* ti;
	void setUp();

public:
	virtual void test();
};

class TestTurnstile_Init : public TestTurnstile
{
public:
	void test() override;
};

class TestTurnstile_Coin : public TestTurnstile
{
public:
	void test() override;
};

class TestTurnstile_CoinAndPass : public TestTurnstile
{
public:
	void test() override;
};

class TestTurnstile_TwoCoins : public TestTurnstile
{
public:
	void test() override;
};

class TestTurnstile_Pass : public TestTurnstile
{
public:
	void test() override;
};

class TestTurnstile_CancelAlarm : public TestTurnstile
{
public:
	void test() override;
};

class TestTurnstile_TwoOperations : public TestTurnstile
{
public:
	void test() override;
};
#endif // __TEST_TURNSTILE__