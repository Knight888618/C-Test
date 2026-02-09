#include <iostream>
using namespace std;
//运算符重载(也可以发生函数重载)
/*
	运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以
					适应不同的数据类型
	对于内置的数据类型，编译器知道如何运算
		int a=10;
		int b=20;
		int c=a+b;	
	总结：
		1.对于内置的数据类型的表达式运算符是不可能修改的 比如1+1=2
		2.不要滥用运算符重载
*/
//加号运算符重载
//作用：实现两个自定义数据类型相加的运算
//1.成员函数重载 + 号
//2.全局函数重载 + 号
class Person
{
public:
	//1.成员函数重载+号
	//本质：Person p3=p1+p2;   -->>>   Person p3=p1.operator+(p2);
	/*Person operator+(Person &p)
	{
		Person temp;
		temp.m_A =this->m_A +p.m_A;
		temp.m_B =this->m_B +p.m_B;
		return temp;
	}*/
	int m_A;
	int m_B;
};
//2.全局函数重载
//全局函数重载本质：Person p3=operator+(p1,p2);
/*Person operator+(Person &p1,Person &p2)
{
	Person temp;
	temp.m_A=p1.m_A +p2.m_A;
	temp.m_B =p1.m_B +p2.m_B;
	return temp;
}*/
/*Person operator+(Person &p1,int p2)
{
	Person temp;
	temp.m_A=p1.m_A +p2
	return temp;
}*/
void test01()
{
	Person p1,p2;
	p1.m_A=10;
	p1.m_B=10;
	p2.m_A=20;
	p2.m_B=20;
	
	Person p3=p1+p2;
	cout<<"p3 a:"<<p3.m_A<<endl;
	cout<<"p3 b:"<<p3.m_B<<endl;
}
int main()
{
	test01();
	return 0;
}
