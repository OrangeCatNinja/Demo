#include "Observer.h"
#include <iostream>

int main()
{
	ConcreteSubject subj;

	ConcreteObject1* obj1 = new ConcreteObject1("观察者1");
	ConcreteObject1* obj2= new ConcreteObject1("观察者2");

	subj.add(obj1);
	subj.add(obj2);

	subj.notify();
}

