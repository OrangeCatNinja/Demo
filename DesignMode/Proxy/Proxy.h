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

class Pursuit : public IGiveGift	//追求者---本人
{
public:
	Pursuit(SchoolGirl girl)
	{
		this->girl = girl;
	}

	virtual void giveDolls() override
	{
		std::cout << std::string(girl.name) << ",送你洋娃娃" << std::endl;
	}

	virtual void giveFlower() override
	{
		std::cout << girl.name << ",送你花花" << std::endl;
	}

	virtual void giveChocolate() override
	{
		std::cout << girl.name << ",送你巧克力" << std::endl;
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
