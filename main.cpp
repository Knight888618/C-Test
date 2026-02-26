#include<iostream>
using namespace std;
void test1(int a)
{
	a++;
}
void test2(int *a)
{
	(*a)++;
}
int main()
{
	int aa=10,bb=10;
	int *p=&bb;
	test1(aa);
	aa=aa<<1;
	test2(p);
	cout<<"aa:"<<aa<<"bb:"<<bb<<endl;
}
/*
int a=10;   -> 4字节 -> 1字节等于4位
0000 0000 0000 1010
0000 0000 0001 0100
a<<1



*/












