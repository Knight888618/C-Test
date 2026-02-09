#include <iostream>
using namespace std;
//继承
/*
	继承是面向对象的三大特性之一
	有些类与类之间存在特殊关系，定义类时，下级别的成员除了拥有上一级的 <共性>
	还有自己的 <特性> ，这个时候我们就可以考虑利用继承技术，减少重复代码
	
	继承的基本语法: class 子类 : 继承方式 父类
	好处： 减少重复代码
	子类 也称为 派生类
	父类 也称为 基类
	
	派生类中的成员，包含两大部分：
		一类是从基类继承过来，一类是自己增加的成员。
		从基类继承过来的表现其共性，而新增的成员体现了其个性
	
*/
//继承
class BasePage
{
public:
	void header()
	{
		cout<<"首页,公开课，登陆，注册.....(公共头部)"<<endl;
	}
	void footer()
	{
		cout<<"帮助中心,交流合作，站内地图.....(公共底部)"<<endl;
	}
};
//Java页面
class Java: public BasePage
{
public:
	void content()
	{
		cout<<"Java学科视频"<<endl;
	}
};
void test01()
{
	Java java;
	cout<<"这是Java页面"<<endl;
	java.header();
	java.content();
	java.footer();
	 
}
int main()
{
	test01();
	return 0;
}
