#ifndef PROXY
#define PROXY

#include <iostream>
#include <string>

class SchoolGirl
{
public:
	char* name;
	SchoolGirl() {};
};

class IGiveGift
{
public:
	virtual void giveDolls() = 0;
	virtual void giveFlower() = 0;
	virtual void giveChocolate() = 0;
};

class Pursuit : public IGiveGift	//׷����---����
{
public:
	Pursuit(SchoolGirl girl)
	{
		this->girl = girl;
	}

	virtual void giveDolls() override
	{
		std::cout << std::string(girl.name) << ",����������" << std::endl;
	}

	virtual void giveFlower() override
	{
		std::cout << girl.name << ",���㻨��" << std::endl;
	}

	virtual void giveChocolate() override
	{
		std::cout << girl.name << ",�����ɿ���" << std::endl;
	}

private:
	SchoolGirl girl;
};

class Proxy : public IGiveGift
{
public:
	Proxy(SchoolGirl girl)
	{
		pur = new Pursuit(girl);
	}

	virtual void giveDolls() override
	{
		pur->giveDolls();
	}

	virtual void giveFlower() override
	{
		pur->giveFlower();
	}

	virtual void giveChocolate() override
	{
		pur->giveChocolate();
	}

private:
	Pursuit* pur;
};

#endif // !PROXY
