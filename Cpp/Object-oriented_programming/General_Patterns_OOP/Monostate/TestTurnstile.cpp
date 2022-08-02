#include "TestTurnstile.h"
#include <cassert>

void TestTurnstile::setUp()
{
	ti = new Turnstile();
	Turnstile().reset();
}

void TestTurnstile::test()
{
	setUp();
}

void TestTurnstile_Init::test()
{
	TestTurnstile::test();

	Turnstile* t = new Turnstile();
	assert(t->locked());
	assert(!t->alarm());
	delete t;
}

void TestTurnstile_Coin::test()
{
	TestTurnstile::test();

	Turnstile* t = new Turnstile();
	t->coin();
	Turnstile* t1 = new Turnstile();
	assert(!t1->locked());
	assert(!t1->alarm());
	assert(1 == t1->coins());
	delete t;
	delete t1;
}

void TestTurnstile_CoinAndPass::test()
{
	TestTurnstile::test();

	Turnstile* t = new Turnstile();
	t->coin();
	t->pass();
	Turnstile* t1 = new Turnstile();
	assert(t1->locked());
	assert(!t1->alarm());
	assert(1 == t1->coins());
	delete t;
	delete t1;
}

void TestTurnstile_TwoCoins::test()
{
	TestTurnstile::test();

	Turnstile* t = new Turnstile();
	t->coin();
	t->coin();
	Turnstile* t1 = new Turnstile();
	assert(!t1->locked());
	assert(1 == t1->coins());
	assert(1 == t1->refunds());
	assert(!t1->alarm());
	delete t;
	delete t1;
}

void TestTurnstile_Pass::test()
{
	TestTurnstile::test();

	Turnstile* t = new Turnstile();
	t->pass();
	Turnstile* t1 = new Turnstile();
	assert(t1->locked());
	assert(t1->alarm());
	delete t;
	delete t1;
}

void TestTurnstile_CancelAlarm::test()
{
	TestTurnstile::test();

	Turnstile* t = new Turnstile();
	t->pass();
	t->coin();
	Turnstile* t1 = new Turnstile();
	assert(!t1->locked());
	assert(!t1->alarm());
	assert(1 == t1->coins());
	assert(0 == t1->refunds());
	delete t;
	delete t1;
}

void TestTurnstile_TwoOperations::test()
{
	TestTurnstile::test();

	Turnstile* t = new Turnstile();
	t->coin();
	t->pass();
	t->coin();
	Turnstile* t1 = new Turnstile();
	assert(!t1->locked());
	assert(2 == t1->coins());
	t->pass();
	assert(t1->locked());
	delete t;
	delete t1;
}