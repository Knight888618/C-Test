#include <iostream>
using namespace std;
//继承中的对象模型
/*
	问题：从父类继承过来的成员，哪些属于子类对象？
*/
class Base
{
public:
	int _a;
protected:
	int _b;
private:
	int _c;
};
class Son :public Base
{
public:
	int _d;
};
void test01()
{
	//父类中所有的非静态成员属性会被子类继承下去
	//父类中的私有成员属性 是被编译器隐藏了 因此访问不到 但是确实被继承了
	cout<<"size of Son ="<<sizeof(Son)<<endl; //内存16 基类私有成员 仍然被继承只是被隐藏
}
int main()
{
	test01();
	return 0;
}
