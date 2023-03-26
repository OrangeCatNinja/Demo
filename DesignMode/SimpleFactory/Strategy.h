#ifndef STRATEGY
#define STRATEGY

#include <iostream>

class Strategy
{
public:
	virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA :public Strategy
{
public:
	ConcreteStrategyA()
	{
	}
	~ConcreteStrategyA()
	{
	}
	void AlgorithmInterface() override
	{
		std::cout << "具体算法A实现" << std::endl;
	}
};

class ConcreteStrategyB :public Strategy
{
public:
	ConcreteStrategyB()
	{
	}
	~ConcreteStrategyB()
	{
	}
	void AlgorithmInterface() override
	{
		std::cout << "具体算法B实现" << std::endl;
	}
};

class ConcreteStrategyC :public Strategy
{
public:
	ConcreteStrategyC()
	{
	}
	~ConcreteStrategyC()
	{
	}
	void AlgorithmInterface() override
	{
		std::cout << "具体算法C实现" << std::endl;
	}
};

class Context
{
public:
	Context(char type)
	{
		if (type == 'a')
			strategy = new ConcreteStrategyA();
		else if (type == 'b')
			strategy = new ConcreteStrategyB();
		else if (type == 'c')
			strategy = new ConcreteStrategyC();
		else
			strategy = NULL;
	}
	~Context()
	{
		if (strategy)
			delete strategy;
	}

	void getResult()
	{
		if (strategy)
			strategy->AlgorithmInterface();
	}

private:
	Strategy* strategy;
};

#endif // !STRATEGY
