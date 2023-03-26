#ifndef STATE
#define STATE

#include <iostream>

class State;
class Context;
class StateA;
class StateB;

class State
{
public:
	virtual void handle(Context* context) = 0;
};

class StateA : public State
{
public:
	virtual void handle(Context* context) override
	{
		context->setState(new StateB());
		std::cout << "状态从A到B" << std::endl;
	}
};

class StateB : public State
{
public:
	virtual void handle(Context* context) override
	{
		context->setState(new StateA());
		std::cout << "状态从B到A" << std::endl;
	}
};

class Context
{
public:
	Context(State* state)
	{
		this->state = state;
	}

	State* getState()
	{
		return state;
	}

	void setState(State* st)
	{
		state = st;
	}

	void request()
	{
		state->handle(this);
	}

private:
	State* state;
};

#endif // !STATE
