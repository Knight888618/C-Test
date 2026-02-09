#include <iostream>
using namespace std;
//继承中构造和析构的顺序
/*
	子类继承父类后，当创建子类对象也会调用父类的构造函数
	
	问题：父类和子类的构造和析构顺序谁先谁后？
	先构造父类，在构造子类，析构的顺序与构造相反
*/

class Base
{
public:
	Base()
	{
		cout<<"基类的构造函数"<<endl;
	}
	~Base()
	{
		cout<<"基类的析构函数"<<endl;
	}
};
class Son : public Base
{
public:
	Son()
	{
		cout<<"子类的构造函数"<<endl;
	}
	~Son()
	{
		cout<<"子类的析构函数"<<endl;
	}
};
void test01()
{
	//创建子类对象 继承中的构造和析构顺序如下：
	//先构造父类，在构造子类，析构的顺序与构造相反
	
	Son son;
}
int main()
{
	test01();
	return 0;
}
