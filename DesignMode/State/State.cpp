#include <iostream>
#include "State.h"

int main()
{
	Context c(new StateA);

	c.request();
	c.request();
	c.request();
	c.request();
	c.request();
}
