#ifndef __TRANSACTION_H__
#define __TRANSACTION_H__

class Transaction
{
public:
	virtual ~Transaction() {};
	virtual void Execute() = 0;
};

#endif // !__TRANSACTION_H__