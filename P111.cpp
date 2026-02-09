#include <iostream>
using namespace std;
//初始化列表
/*
	作用：C++提供了初始化列表语法，用来初始化属性
	语法：构造函数() : 属性1(值1), 属性2(值2)......{}
*/
class Person
{
public:
	//传统的构造函数赋值
	/*
	Person(int age,int a,int b)
	{
		int m_age=age;
		int m_a=a;
		int m_b=b;
	}
	*/
	
	//Person():m_age(10),m_a(20),m_b(30) {}
	Person(int a,int b,int c):m_age(a),m_a(b),m_b(c) {}
	int m_age;
	int m_a;s
	int m_b;
};
void test01()
{
	Person p(10,20,30);
	cout<<"m_age:"<<p.m_age<<endl;
	cout<<"m_a:"<<p.m_a<<endl;
	cout<<"m_b:"<<p.m_b<<endl;
}
int main()
{
	test01();
	return 0;
}
