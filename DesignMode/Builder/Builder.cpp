#include <iostream>
#include "Builder.h"

int main()
{
	Director dir;
	Builder* builder1 = new ConcreteBuilderA();
	Builder* builder2 = new ConcreteBuilderB();

	dir.Construct(builder1);
	Product p1 = builder1->GetResult();
	p1.Show();
}
