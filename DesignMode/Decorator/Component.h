#ifndef COMPONENT
#define COMPONENT

#include <iostream>

class Component
{
public:
	virtual void Operation() = 0;
};

class ConcreteComponent : public Component
{
public:
	virtual void Operation() override
	{
		std::cout << "具体对象的操作" << std::endl;
	}
};

class Decorator : public Component
{
protected:
	Component* component;

public:
	void setComponent(Component* com)
	{
		component = com;
	}

	virtual void Operation() override
	{
		if (component != NULL)
		{
			component->Operation();
		}
	}
};

class ContreteDecoratorA : public Decorator
{
private:
	char* addedState;

public:
	virtual void Operation() override
	{
		Decorator::Operation();
		//addedState = "New State";
		std::cout << "具体装饰A生效了" << std::endl;
	}
};

class ContreteDecoratorB : public Decorator
{
public:
	void Operation() override
	{
		Decorator::Operation();
		std::cout << "具体装饰B生效了" << std::endl;
	}
};

#endif // !COMPONENT
