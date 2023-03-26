#ifndef ABSTRACTFACTORY
#define ABSTRACTFACTORY

#include <iostream>

class User
{
public:
	void setID(int id) { this->id = id; }
	void setName(int id) { this->name = name; }
	int getID() { return id; }
	int getName() { return name; }

private:
	int id;
	int name;
};

class Department
{
public:
	void setID(int id) { this->id = id; }
	void setName(int id) { this->name = name; }
	int getID() { return id; }
	int getName() { return name; }

private:
	int id;
	int name;
};

/*********************************************/

class IUser//User��Ʒ����
{
public:
	virtual void insertUserRed() = 0;
	virtual User* getUser() = 0;
};

class SqlServerUser : public IUser//SQLServer��Ʒ��
{
public:
	virtual void insertUserRed() override
	{
		std::cout << "SQLServer����User��¼" << std::endl;
	}

	virtual User* getUser() override
	{
		std::cout << "SqlServer��ȡUser��¼" << std::endl;
		return new User();
	}
};

class AccessServerUser : public IUser//AccessServer��Ʒ��
{
public:
	virtual void insertUserRed() override
	{
		std::cout << "AccessServer����User��¼" << std::endl;
	}

	virtual User* getUser() override
	{
		std::cout << "AccessServer��ȡUser��¼" << std::endl;
		return new User();
	}
};

/**********************************************/

class IDepartment//Department��Ʒ����
{
public:
	virtual void insertDepartmentRed() = 0;
	virtual Department* getDepartment() = 0;
};

class SqlServerDepartment : public IDepartment//SQLServer��Ʒ��
{
public:
	virtual void insertDepartmentRed() override
	{
		std::cout << "SQLServer����Department��¼" << std::endl;
	}

	virtual Department* getDepartment() override
	{
		std::cout << "SqlServer��ȡDepartment��¼" << std::endl;
		return new Department();
	}
};

class AccessServerDepartment : public IDepartment//AccessServer��Ʒ��
{
public:
	virtual void insertDepartmentRed() override
	{
		std::cout << "AccessServer����Department��¼" << std::endl;
	}

	virtual Department* getDepartment() override
	{
		std::cout << "AccessServer��ȡDepartment��¼" << std::endl;
		return new Department();
	}
};

/**********************************************/

class IFactory//���󹤳�
{
public:
	virtual IUser* CreateUser() = 0;
	virtual IDepartment* CreateDepartment() = 0;
};

class SqlServerFactory : public IFactory
{
public:
	virtual IUser* CreateUser() override
	{
		return new SqlServerUser();
	}

	virtual IDepartment* CreateDepartment() override
	{
		return new SqlServerDepartment();
	}
};

class AccessServerFactory : public IFactory
{
public:
	virtual IUser* CreateUser() override
	{
		return new AccessServerUser();
	}

	virtual IDepartment* CreateDepartment() override
	{
		return new AccessServerDepartment();
	}
};

/**********************************************/

//class DataBaseConn
//{
//	virtual void CreateConn() = 0;
//	virtual void select() = 0;
//	virtual void insert() = 0;
//	virtual void update() = 0;
//	virtual void del() = 0;
//};
//
////class AccessDB : public DataBaseConn
////{
////	virtual void CreateConn() override
////	{
////		std::cout << "Access���ݿⴴ������" << std::endl;
////	}
////
////	virtual void select()
////	{
////		std::cout << "Access���ݿ�ִ��select()" << std::endl;
////	}
////
////	virtual void insert()
////	{
////		std::cout << "Access���ݿ�ִ��insert()" << std::endl;
////	}
////
////	virtual void update()
////	{
////		std::cout << "Access���ݿ�ִ��update()" << std::endl;
////	}
////
////	virtual void del()
////	{
////		std::cout << "Access���ݿ�ִ��del()" << std::endl;
////	}
////};
////
////class MysqlDB :public DataBaseConn
////{
////	virtual void CreateConn() override
////	{
////		std::cout << "Mysql���ݿⴴ������" << std::endl;
////	}
////
////	virtual void select()
////	{
////		std::cout << "Mysql���ݿ�ִ��select()" << std::endl;
////	}
////
////	virtual void insert()
////	{
////		std::cout << "Mysql���ݿ�ִ��insert()" << std::endl;
////	}
////
////	virtual void update()
////	{
////		std::cout << "Mysql���ݿ�ִ��update()" << std::endl;
////	}
////
////	virtual void del()
////	{
////		std::cout << "Mysql���ݿ�ִ��del()" << std::endl;
////	}
////};

#endif // !ABSTRACTFACTORY
