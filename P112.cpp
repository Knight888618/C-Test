#include <iostream>
using namespace std;
//类对象作为类成员
/*
	C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员
	例如：(B类中有对象A作为成员，A为对象成员)
		class A{};
		class B
		{
			A a;
		};
		
	那么，当创建B对象时，A与B的构造和析构的顺序是谁先谁后？
		A构造函数->B构造函数->B析构函数->A析构函数
		构造顺序：先调用对象成员的构造，再调用本类的构造
		析构顺序与构造相反

*/
class Phone 
{
public:
	string p_name;
	Phone(string pname)
	{
		p_name=pname;
		cout<<"Phone类的有参构造函数"<<endl;
	}
	~Phone() 
	{
		cout<<"Phone类的析构函数"<<endl;
	}


};
class Person
{
public:
	//姓名
	string m_name;
	//手机
	Phone m_phone;//
	//初始化列表
	//Phone m_phone =pname; //隐式转换法
	Person(string name,string pname):m_name(name),m_phone(pname) 
	{
		cout<<"Person类的有参构造函数"<<endl;
	}
	~Person() 
	{
		cout<<"Person类的析构函数"<<endl;
	}
	
};
void test01()
{
	Person p("张三","IPhone");
	cout<<p.m_name<<"拿着"<<p.m_phone.p_name<<endl;
}
int main()
{
	test01();
	return 0;
}
