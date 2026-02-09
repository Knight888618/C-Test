#include <iostream>
using namespace std;
//深拷贝与浅拷贝
/*
	深浅拷贝是面试经典问题！！！
		浅拷贝：简单的赋值拷贝操作
		深拷贝：在堆区重新申请空间，进行拷贝操作
		
	
					->	普通构造（无参构造）
	构造函数		->	有参构造
（构造函数调用规则）->	拷贝构造		->浅拷贝
	        			（拷贝构造函数调用时机）->深拷贝
*/
class Person
{
public:
	Person()
	{
		cout<<"Person的默认构造函数调用"<<endl;
	}
	Person(int age,int height)
	{
		m_age=age;
		m_height=new int(height);
		cout<<"Person的有参构造函数调用"<<endl;
	}
	~Person()
	{
		cout<<"Person的析构函数调用"<<endl;
	}
	
int m_age;
int *m_height;
};
void test01()
{
	Person p1(18);
	cout<<"p1年龄："<<p1.m_age<<endl;
	cout<<"p1身高："<<*p1.m_height<<endl;
	Person p2(p1);
	cout<<"p2=年龄："<<p2.m_age<<endl;
	cout<<"p2身高："<<*p2.m_height<<endl;
}
int main()
{
	test01();
	return 0;
}









