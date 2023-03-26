#ifndef BUILDER
#define BUILDER

#include <iostream>
#include <vector>

class Product
{
public:
	std::vector<std::string> partVec;

	void Add(std::string part)
	{
		partVec.push_back(part);
	}

	void Show()
	{
		for (std::vector<std::string>::iterator itr = partVec.begin(); itr != partVec.end(); itr++)
		{
			std::cout << "\n��Ʒ����--------" << std::endl;
			std::cout << (*itr).c_str() << std::endl;
		}
	}
};

class Builder
{
public:
	virtual void BuildPartA() = 0;
	virtual void BuildPartB() = 0;
	virtual void BuildPartC() = 0;
	virtual Product GetResult() = 0;
};

class ConcreteBuilderA : public Builder
{
public:
	virtual void BuildPartA() override
	{
		prod.Add("ģ��A");
	}

	virtual void BuildPartB() override
	{
		prod.Add("ģ��B");
	}

	virtual void BuildPartC() override
	{
		prod.Add("ģ��C");
	}

	virtual Product GetResult() override
	{
		return prod;
	}

private:
	Product prod;
};

class ConcreteBuilderB : public Builder
{
public:
	virtual void BuildPartA() override
	{
		prod.Add("����X");
	}

	virtual void BuildPartB() override
	{
		prod.Add("����Y");
	}

	virtual void BuildPartC() override
	{
		prod.Add("����Z");
	}

	virtual Product GetResult() override
	{
		return prod;
	}

private:
	Product prod;
};

class Director
{
public:
	void Construct(Builder* builder)
	{
		builder->BuildPartA();
		builder->BuildPartB();
		builder->BuildPartC();
	}
};

#endif // !BUILDER
