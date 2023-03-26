#include <iostream>
#include "Component.h"

int main()
{
	ConcreteComponent* c = new ConcreteComponent();
	ContreteDecoratorA* d1 = new ContreteDecoratorA();
	ContreteDecoratorB* d2 = new ContreteDecoratorB();

	d1->setComponent(c);
	d2->setComponent(d1);
	d2->Operation();
}

