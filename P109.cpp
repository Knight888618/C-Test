#include <iostream>
using namespace std;
//构造函数调用规则
/*
	默认情况下C++编译器至少给一个类添加三个函数
	1.默认构造函数（空实现）
	2.默认析构函数（空实现）
	3.默认拷贝构造函数，对属性进行拷贝(值拷贝--当我不写拷贝构造函数时候，所有属性值直接拷贝给新对象)
	
	构造函数调用规则如下：
		1.如果用户自定义有参构造函数，c++不再提供默认无参构造函数，但会提供默认拷贝构造
		2.如果用户定义拷贝构造函数，c++编译器不会再提供其他构造函数
		{
			1.无参构造
			2.有参构造
			3.拷贝构造
			按顺序 构造函数有2 无1
				   构造函数有3 无2 1
			
		
		}
*/
class Person
{
public:
	/*
	Person()
	{
		cout<<"Person无参构造函数\r\n"<<endl;
	}*/
	Person(int age)
	{
		m_age=age;
		cout<<"Person有参构造函数\r\n"<<endl;
	}
	/*Person(const Person & p)
	{
		m_age=p.m_age;
		cout<<"Person拷贝构造函数\r\n"<<endl;
	}*/
	~Person()
	{
		cout<<"Person析构函数\r\n"<<endl;
	}
	int m_age;
};
void test01()
{
	Person p(18);
	Person p2(p);
	cout<<"P2的年龄为："<<p2.m_age<<endl;
}
void test02()
{
	//Person p;//若是仅有有参构造函数 无无参构造函数 则会报错->没有无参构造函数
	Person p1(18);
	Person p2(p1);//但是编译器会提供默认的拷贝构造函数
}
int main()
{
	test01();
	test02();
	return 0;
}
