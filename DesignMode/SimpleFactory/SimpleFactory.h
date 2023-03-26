#ifndef SIMPLEFACTORY
#define SIMPLEFACTORY

#include <iostream>

class Operation;

class Operation
{
public:
	Operation()
		:m_num1(0), m_num2(0)
	{

	}

	~Operation()
	{

	}

	double getNum1() { return m_num1; }
	double getNum2() { return m_num2; }
	void setNum1(double num) { m_num1 = num; }
	void setNum2(double num) { m_num2 = num; }

	virtual double getRet() { double result = 0; return result; }

protected:
	double m_num1;
	double m_num2;
};

class OperatorFactory
{
public:
	OperatorFactory()
	{
	}
	~OperatorFactory()
	{
	}

	Operation* createOperate(const char operation);

private:

};

class OperationAdd :public Operation
{
public:
	virtual double getRet() override
	{
		double result = 0;
		result = m_num1 + m_num2;
		return result;
	}
};

class OperationSub : public Operation
{
public:
	virtual double getRet() override
	{
		double result = 0;
		result = m_num1 - m_num2;
		return result;
	}
};

class OperationMul : public Operation
{
public:
	virtual double getRet() override
	{
		double result = 0;
		result = m_num1 * m_num2;
		return result;
	}
};

class OperationDiv : public Operation
{
public:
	virtual double getRet() override
	{
		double result = 0;
		if (m_num2 == 0)
		{
			std::cout << "除数不能为0" << std::endl;
			return 0;
		}

		result = m_num1 / m_num2;
		return result;
	}
};

inline Operation* OperatorFactory::createOperate(const char operation)
{
	Operation* oper = NULL;

	if (operation == '+')
	{
		oper = new OperationAdd();
	}
	else if (operation == '-')
	{
		oper = new OperationSub();
	}
	else if (operation == '*')
	{
		oper = new OperationMul();
	}
	else if (operation == '/')
	{
		oper = new OperationDiv();
	}
	else
	{

	}

	return oper;
}

#endif // !SIMPLEFACTORY