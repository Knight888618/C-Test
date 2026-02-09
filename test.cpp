#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout<<"类的无参构造函数调用"<<endl;
	}
	Person(const Person & p)
	{
		this->
		cout<<"拷贝构造函数构造函数调用"<<endl;
	}
	Person(int a)
	{
		money=a;
		p=new int(10);
		cout<<"类的有参构造函数调用"<<endl;
	}
	~Person()
	{
		delete p;
		cout<<"类的析构函数调用"<<endl;
	}
	string car;
	
	void Get_money()
	{
		cout<<money<<endl;
	}
	
private:
	int money;
	int *p;
};
void test01()
{
	Person Sjx(10);
	Person SJX(Sjx);
	Sjx.Get_money();
}
int main()
{
	test01();
	return 0;
}
