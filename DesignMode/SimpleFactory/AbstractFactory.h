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

class IUser//User产品基类
{
public:
	virtual void insertUserRed() = 0;
	virtual User* getUser() = 0;
};

class SqlServerUser : public IUser//SQLServer产品类
{
public:
	virtual void insertUserRed() override
	{
		std::cout << "SQLServer插入User记录" << std::endl;
	}

	virtual User* getUser() override
	{
		std::cout << "SqlServer获取User记录" << std::endl;
		return new User();
	}
};

class AccessServerUser : public IUser//AccessServer产品类
{
public:
	virtual void insertUserRed() override
	{
		std::cout << "AccessServer插入User记录" << std::endl;
	}

	virtual User* getUser() override
	{
		std::cout << "AccessServer获取User记录" << std::endl;
		return new User();
	}
};

/**********************************************/

class IDepartment//Department产品基类
{
public:
	virtual void insertDepartmentRed() = 0;
	virtual Department* getDepartment() = 0;
};

class SqlServerDepartment : public IDepartment//SQLServer产品类
{
public:
	virtual void insertDepartmentRed() override
	{
		std::cout << "SQLServer插入Department记录" << std::endl;
	}

	virtual Department* getDepartment() override
	{
		std::cout << "SqlServer获取Department记录" << std::endl;
		return new Department();
	}
};

class AccessServerDepartment : public IDepartment//AccessServer产品类
{
public:
	virtual void insertDepartmentRed() override
	{
		std::cout << "AccessServer插入Department记录" << std::endl;
	}

	virtual Department* getDepartment() override
	{
		std::cout << "AccessServer获取Department记录" << std::endl;
		return new Department();
	}
};

/**********************************************/

class IFactory//抽象工厂
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
////		std::cout << "Access数据库创建连接" << std::endl;
////	}
////
////	virtual void select()
////	{
////		std::cout << "Access数据库执行select()" << std::endl;
////	}
////
////	virtual void insert()
////	{
////		std::cout << "Access数据库执行insert()" << std::endl;
////	}
////
////	virtual void update()
////	{
////		std::cout << "Access数据库执行update()" << std::endl;
////	}
////
////	virtual void del()
////	{
////		std::cout << "Access数据库执行del()" << std::endl;
////	}
////};
////
////class MysqlDB :public DataBaseConn
////{
////	virtual void CreateConn() override
////	{
////		std::cout << "Mysql数据库创建连接" << std::endl;
////	}
////
////	virtual void select()
////	{
////		std::cout << "Mysql数据库执行select()" << std::endl;
////	}
////
////	virtual void insert()
////	{
////		std::cout << "Mysql数据库执行insert()" << std::endl;
////	}
////
////	virtual void update()
////	{
////		std::cout << "Mysql数据库执行update()" << std::endl;
////	}
////
////	virtual void del()
////	{
////		std::cout << "Mysql数据库执行del()" << std::endl;
////	}
////};

#endif // !ABSTRACTFACTORY
