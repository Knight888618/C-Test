#include <iostream>
using namespace std;
//多态案例分析2-制作饮品
/*
	案例描述：
		制作茶品的大致流程为：煮茶-冲泡-倒入杯中-加入辅料
		
		利用多态技术实现案例，提供抽象制作饮品基类 提供子类制作咖啡和茶叶
*/
class MakeTea
{
public:
	virtual void BoilTea() =0;//煮茶
	virtual void SteepTea() =0;//冲泡
	virtual void PourIntoTea() =0;//倒入被杯中
	virtual void AuxyMlTea() =0;//加入辅料
};
class MakeCoffe:public MakeTea
{
public:
	virtual void BoilTea(){cout<<"烧咖啡开水"<<endl;}
	virtual void SteepTea(){cout<<"冲泡咖啡"<<endl;}
	virtual void PourIntoTea(){cout<<"将咖啡倒入杯中"<<endl;}
	virtual void AuxyMlTea(){cout<<"加入咖啡辅料"<<endl;}
};
class MakeMyTea:public MakeTea
{
public:
	virtual void BoilTea(){cout<<"烧茶叶开水"<<endl;}
	virtual void SteepTea(){cout<<"冲泡茶叶"<<endl;}
	virtual void PourIntoTea(){cout<<"将茶叶倒入杯中"<<endl;}
	virtual void AuxyMlTea(){cout<<"加入茶叶辅料"<<endl;}
};
void test01()
{
	MakeTea *maketeac = new MakeCoffe;
	cout<<"制作咖啡流程"<<endl;
	maketeac->BoilTea();
	maketeac->SteepTea();
	maketeac->PourIntoTea();
	maketeac->AuxyMlTea();
	cout<<"制作茶叶流程"<<endl;
	MakeTea *maketeam = new MakeMyTea;
	maketeam->BoilTea();
	maketeam->SteepTea();
	maketeam->PourIntoTea();
	maketeam->AuxyMlTea();
	//释放堆区内存
	delete maketeam;
	delete maketeac;
}
int main()
{
	test01();
	return 0;
}
