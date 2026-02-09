#include <iostream>
using namespace std;
//继承的方式
/*
	继承方式一共有三种：
		公共继承 
		保护继承
		私有继承
*/
//公共继承
class Base1
{
public:
	int a;
protected:
	int b;
private:
	int c;
};
class Son1:public Base1
{
public:
	void func()
	{
		a=10; //父类中的公共权限成员 到子类中依然是公共权限
		b=10; //父类中的保护权限成员 到子类中依然是保护权限
		//c=10; //父类中的私有权限成员 子类访问不到 继承不到
	}
};
class Son2:protected Base1
{
public:
	void func()
	{
		a=10; //父类中的公共权限成员 到子类中 保护权限
		b=10; //父类中的保护权限成员 到子类中 保护权限
		//c=10; //父类中的私有权限成员 子类依然访问不到
	}
};
class Son3:private Base1
{
public:
	void func()
	{
		a=10; //父类中的公共权限成员 到子类中 私有权限
		b=10; //父类中的保护权限成员 到子类中 私有权限
		//c=10; //父类中的私有权限成员 子类依然访问不到
	}
};
void test01()
{
	Son1 son1;
	son1.a =10; //公共权限成员类外可以访问到
	//son1.b =10; //父类中的保护权限成员 外界访问不到
}
void test02()
{
	Son2 son2;
	son2.a =10; //子类保护继承 到子类中是保护权限 外界访问不到
	//son1.b =10; //父类中的保护权限成员 外界访问不到
}
void test03()
{
	Son3 son3;
	//son3.a =10; //子类私有继承 到子类中是私有权限 外界访问不到
	//son1.b =10; //父类中的保护权限成员 外界访问不到
}
class GrandSon3:public Son3
{	
public:
	void func()
	{
		//a=10;//Son3中 变为 私有成员 GrandSon3仍然会被继承 但是访问不到
	}

};
int main()
{
	test03();
	return 0;
}
