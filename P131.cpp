#include <iostream>
using namespace std;
//继承同名成员的处理方式
/*
	问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类
		  同名的数据呢？
		  
		  1.访问子类同名成员，直接访问即可 
		  2.访问父类同名成员 需要加作用域 son.Base::_a  son.Base::func()
*/
class Base
{
public:
	int _a;
	Base()
	{
		_a=100;
	}
	void func()
	{
		cout<<"Base下的func()调用"<<endl;
	}
	void func(int a)
	{
		cout<<"Base下的有参func()调用"<<endl;
	}
};
class Son :public Base
{
public:
	int _a;
	Son()
	{
		_a =200;
	}
	void func()
	{
		cout<<"Son下的func()调用"<<endl;
	}
	
};
//同名成员属性
void test01()
{
	Son son;
	cout<<"Son下的_a ="<<son._a<<endl;
	//如果通过子类对象 访问到父类中同名成员 需要加作用域
	cout<<"Base下的_a ="<<son.Base::_a<<endl; 
}
//同名成员函数处理方式
void test02()
{
	Son son;
	son.func(); //直接调用 调用的是子类的同名成员函数
	//那如何调用到父类的同名成员函数呢？ (加作用域)
	son.Base::func();
	
	//如果子类中出现了和父类同名的成员函数 子类的同名成员会隐藏掉父类的所有同名
	//成员函数，如果想访问到父类中被隐藏的成员函数，需要加作用域
	//son.func(100);//会报错
	son.Base::func(100);
	
}
int main()
{
	//test01();
	test02();
	return 0;
}
