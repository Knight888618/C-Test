#include <iostream>
using namespace std;
//多态案例---计算器类 细品
/*
	案例描述：
		分别利用普通写法和多态技术，设计实现两个操作进行运算的计算机类
	多态的优点：
		代码组织结构清晰
		可读性强
		利于前期和后期的扩展以及为维护
*/
class Calculator
{
public:
	int getResult(char oper)
	{
		switch(oper){
		case '+':
			return m_Num1+m_Num2;
		case '-':
			return m_Num1-m_Num2;
		case '*':
			return m_Num1*m_Num2; 
		case '/':
			return m_Num1/m_Num2;
		default:
            return -1;
          //如果想扩展新的功能，需要修改源码
          //在真实开发中 提倡 开闭原则
          //开闭原则：对扩展进行开放，对修改进行关闭
		}
	}
	int m_Num1;//操作数1
	int m_Num2;//操作数2
};
void test01()
{
	Calculator c;
	c.m_Num1=10;
	c.m_Num2=20;
	cout<<c.m_Num1<<"+"<<c.m_Num2<<"="<<c.getResult('+')<<endl;
	cout<<c.m_Num1<<"-"<<c.m_Num2<<"="<<c.getResult('-')<<endl;
	cout<<c.m_Num1<<"*"<<c.m_Num2<<"="<<c.getResult('*')<<endl;
	cout<<c.m_Num1<<"/"<<c.m_Num2<<"="<<c.getResult('/')<<endl;
}
//利用多态实现计算器类
//实现计算器抽象类
class AbstractCalculator
{
public:
	virtual int getResult(){return 0;}
	int m_Num1;
	int m_Num2;
};
//加法计算器类
class AddCalculator:public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_Num1+m_Num2;
	}
};
class SubCalculator:public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_Num1-m_Num2;
	}
};
class MulCalculator:public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_Num1*m_Num2;
	}
};
void test02()
{
	//多态使用条件
	//父类指针或者引用指向子类对象
	//加法计算器
	AbstractCalculator *abc=new AddCalculator;
	abc->m_Num1=100;
	abc->m_Num2=10;
	cout<<abc->m_Num1<<"+"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
	//减法计算器
	abc =new SubCalculator;
	abc->m_Num1=100;
	abc->m_Num2=10;
	cout<<abc->m_Num1<<"-"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
	delete abc;
}
int main()
{
	//test01();
	test02();
	return 0;
}













