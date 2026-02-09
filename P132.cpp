#include <iostream>
using namespace std;
//继承中同名静态成员处理方式
/*
	问题：继承中同名的静态成员在子类对象上如何进行访问？
	
	静态成员和非静态成员出现同名，处理方式一样
	
		访问子类同名成员 直接访问即可
		访问父类同名成员 需要加作用域
*/
class Base
{
public:
	static int _a;
	static void func()
	{
		cout<<"Base func"<<endl;
	}
	static void func(int a)
	{
		cout<<"Base func(int a)"<<endl;
	}

};
int Base::_a=100;
class Son:public Base
{
public:
	static int _a;
	static void func()
	{
		cout<<"Son func"<<endl;
	}
};
int Son::_a=200;
//同名的静态成员属性
void test01()
{
	//1.通过对象去访问
	Son son;
	cout<<"Son下的a:"<<son._a<<endl;
	cout<<"Base下的a:"<<son.Base::_a<<endl;
	//2.通过类名访问
	cout<<"Son下的a:"<<Son::_a<<endl;
	cout<<"Base下的a:"<<Base::_a<<endl;
	//第一个::代表通过类名的方式访问 第二个::代表访问父类作用域
	cout<<"Base下的a:"<<Son::Base::_a<<endl;
}
//同名静态函数
void test02()
{
	//通过对象访问
	Son son;
	son.func();
	son.Base::func();
	//2.通过类名访问
	Son::func();
	Son::Base::func();
	//出现函数重载 子类把所有的父类同名函数全部隐藏 访问需要加作用域
	//son.func(100);//错误
	son.Base::func(100);
}
int main()
{
	//test01();
	test02();
	return 0;
}
