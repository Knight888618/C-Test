#include <iostream>
using namespace std;
//虚析构和纯虚析构
/*
	多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的
	析构代码
	解决方式：将父类的析构函数改为虚析构 或者 纯虚析构
	
	虚析构和纯虚析构共性：
		可以解决父类指针释放子类对象
		都需要有具体的函数实现
	虚析构和纯虚析构区别：
		如果是纯虚析构 该类属于抽象类 无法实例化对象
	
	虚析构语法：virtual ~类名(){}
	纯虚析构语法：virtual ~类名()=0;
*/
class Animal
{
public:
	Animal()
	{
		cout<<"Animal构造函数调用"<<endl;
	}
	virtual void speak()=0;
	//利用虚析构可以解决 父类指针释放子类对象时不干净的问题
	//virtual ~Animal() //虚析构 避免内存泄漏
	//{
	//	cout<<"Animal析构函数调用"<<endl;
	//}
	virtual ~Animal()=0;//纯虚析构
};
//纯虚析构--需要声明 需要实现
//有了纯虚析构之后 这个类也属于抽象类 无法实例化对象
Animal::~Animal()
{
	cout<<"Animal纯虚析构函数调用"<<endl;
}
class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout<<"Cat构造函数调用"<<endl;
		m_Name=new string(name);
	}
	virtual void speak()
	{
		cout<<*m_Name<<" Cat Speak!"<<endl;
	}
	~Cat()
	{
		if(m_Name!=NULL)
		{
			cout<<"Cat析构函数调用"<<endl;
			delete m_Name;
		}
	}
	string *m_Name;
};
void test01()
{
	Animal *animal=new Cat("TOM");
	animal->speak();
	//父类指针在析构时候 不会调用子类中析构函数 导致子类如果有堆区属性
	//出现内存泄漏情况 解决方法在 把父类析构函数变为虚析构
	delete animal;
}
int main()
{
	test01();
	return 0;
}









