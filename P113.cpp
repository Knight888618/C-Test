#include <iostream>
using namespace std;
//静态成员变量
/*
	静态成员就是在成员变量和成员函数前加上关键字static,称为静态成员
	静态成员分为：
		静态成员变量(也是有访问权限)：
			所有对象共享同一份数据
			在编译阶段分配内存
			类内声明，类外初始化 int Person::m_A=100;
		静态成员函数(也是有访问权限)：
			所有对象共享同一个函数
			静态成员函数只能访问静态成员变量
*/
//静态成员变量
class Person
{
public:
	//所有对象共享同一份数据
	//在编译阶段分配内存
	//类内声明，类外初始化
	static int m_A;
private:
	static int m_B;
};
int Person::m_A=100;
int Person::m_B=200;
void test01()//类内声明，所有对象共享同一份数据
{
	Person p;
	cout<<p.m_A<<endl;
	
	Person p2;
	p2.m_A=200;
	
	cout<<p.m_A<<endl;
}
void test02()
{
	//静态成员变量 不属于某个对象上，所有对象都共享同一份数据
	/*
		两种访问方式：
			1.通过对象进行访问
			2.通过类名进行访问
	*/
	Person p;  //1.通过对象进行访问
	cout<<p.m_A<<endl;
	cout<<Person::m_A<<endl;//2.通过类名进行访问
	//cout<<Person::m_B<<endl;//类外访问不到私有成员变量
}
//静态成员函数
class Persont
{
public:
	static void func()
	{
		m_A=100;
		//m_B=200;//静态成员函数不可以访问非静态成员变量 无法区分到底是那个对象的 但静态成员变量是共享一份
		cout<<"static void func()调用"<<endl;
	}
	static int m_A;
	int m_B;//非静态成员变量
private:
	static void fun()
	{
		cout<<"private权限静态成员函数"<<endl;
	}
};
int Persont::m_A=100;
void test03()
{
	//访问静态成员函数
	//1.通过对象访问
	Persont p;
	p.func();
	//2.通过类名访问 不用创建对象 不属于某个对象
	Persont::func();
	//Persont::fun();//静态成员函数也是由访问权限
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}
