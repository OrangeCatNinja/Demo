#ifndef OBSERVER
#define OBSERVER

#include <iostream>
#include <vector>
#include <string>

class Observer
{
public:
	virtual void update() = 0;
};

class Subject
{
public:
	void notify()
	{
		for (std::vector<Observer*>::iterator itr = m_vecObs.begin(); itr != m_vecObs.end(); itr++)
		{
			(*itr)->update();
		}
	}
	void add(Observer* obs)
	{
		m_vecObs.push_back(obs);
	}
	void sub()
	{
		m_vecObs.pop_back();
	}

private:
	std::vector<Observer*> m_vecObs;
};

class ConcreteSubject : public Subject
{

};

class ConcreteObject1 : public Observer
{
private:
	std::string name;
	std::string state;
	Subject* pSubject;

public:
	ConcreteObject1(std::string name)
	{
		this->name = name;
	}

	virtual void update() override
	{
		std::cout << "观察者" << name.c_str() << "收到通知，改变状态" << std::endl;
	}
};

#endif // !OBSERVER

