#ifndef MEMENTO
#define MEMENTO

#include <iostream>
#include <string>

class Memento
{
public:
	std::string getState() { return state; }
	Memento(std::string st)
	{
		state = st;
	}

private:
	std::string state;
};

class Originator
{
public:
	std::string getState() { return state; }
	void setState(std::string st) { state = st; }
	Memento CreateMemento()
	{
		return Memento(state);
	}
	void setMemento(Memento memento)
	{
		state = memento.getState();
	}
	void Show()
	{
		std::cout << "State = " << state << std::endl;
	}

private:
	std::string state;
};

class Caretaker
{
public:
	Memento getMem() { return memento; }
	void setMem(Memento mem) { memento = mem; }
private:
	Memento memento;
};

#endif // !MEMENTO
