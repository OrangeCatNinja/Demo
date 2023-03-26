#ifndef ICLONEABLE
#define ICLONEABLE

#include <iostream>

class ICloneable
{
public:
	virtual void clone() = 0;
};

class WorkExperience : public ICloneable
{
public:
	virtual void clone() override
	{
		//ǳ����
		WorkExperience work;
		work.cmpName = this->cmpName;
		work.time = this->time;
		return (WorkExperience)work;

		//���

	}

	void setInfo(char* name, int time)
	{
		cmpName = name;
		this->time = time;
	}

	char* getCompName() { return cmpName; }
	int getTime() { return time; }

private:
	char* cmpName;
	int time;
};

class Resume : public ICloneable
{
public:
	Resume(char* name, int age)
	{
		this->manName = name;
		this->age = age;
		work = new WorkExperience();
	}

private:
	Resume(WorkExperience work)
	{
		this->work = work.clone();
	}

	char* manName;
	int age;
	WorkExperience work;
};

#endif // !ICLONEABLE

