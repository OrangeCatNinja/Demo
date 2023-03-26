#include <iostream>
#include "Proxy.h"

int main()
{
	SchoolGirl jiaojiao;
	jiaojiao.name = const_cast<char*>("娇娇");

	Proxy* daili = new Proxy(jiaojiao);
	daili->giveDolls();
	daili->giveFlower();
	daili->giveChocolate();
}
