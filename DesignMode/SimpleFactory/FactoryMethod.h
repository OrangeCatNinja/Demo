#ifndef FACTORYMETHOD
#define FACTORYMETHOD

#include <iostream>
#include "SimpleFactory.h"

//class Operation;

class IFactory
{
public:
	virtual Operation* CreateOperation() = 0;
};

class AddFactory :public IFactory
{
public:
	virtual Operation* CreateOperation() override
	{
		return new OperationAdd();
	}
};

class SubFactory : public IFactory
{
public:
	virtual Operation* CreateOperation() override
	{
		return new OperationSub();
	}
};

class MulFactory : public IFactory
{
public:
	virtual Operation* CreateOperation() override
	{
		return new OperationMul();
	}
};

class DivFactory :public IFactory
{
public:
	virtual Operation* CreateOperation() override
	{
		return new OperationDiv();
	}
};

#endif // !FACTORYMETHOD

