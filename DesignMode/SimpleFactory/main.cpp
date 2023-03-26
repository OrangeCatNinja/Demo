#include <iostream>
//#include "SimpleFactory.h"
//#include "Strategy.h"
//#include "FactoryMethod.h"
#include "AbstractFactory.h"

int main()
{
	//OperatorFactory factory;

	//Operation* oper;
	//oper = factory.createOperate('+');
	//oper->setNum1(1);
	//oper->setNum2(2);

	//std::cout << "1+2=" << oper->getRet();

	/***************************************************/

	//Context context('a');

	//context.getResult();

	/***************************************************/

	//IFactory* operFactory = new AddFactory();
	//Operation* oper = operFactory->CreateOperation();
	//oper->setNum1(1);
	//oper->setNum2(2);

	//double result = oper->getRet();
	//std::cout << "result is: " << result;

	/***************************************************/

	User* user = new User();
	Department* dept = new Department();

	IFactory* factory = new AccessServerFactory();

	IUser* iuser = factory->CreateUser();
	iuser->insertUserRed();
	iuser->getUser();


	IDepartment* id = factory->CreateDepartment();
	id->insertDepartmentRed();
	id->getDepartment();



	return 0;
}