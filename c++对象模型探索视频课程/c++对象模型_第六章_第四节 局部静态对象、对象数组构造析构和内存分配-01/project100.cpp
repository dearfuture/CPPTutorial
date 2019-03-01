
#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>

using namespace std;

namespace _nmsp1
{	
	//一：局部静态对象的构造和析构
	//a)如果我们不调用myfunc()函数，那么根本不会触发A的构造函数；
	//b)局部静态对象，内存地址是在编译期间就确定好的；
	//c)静态局部量刚开始也被初始化为0；
	//d)局部静态对象的析构，是在main函数执行结束后才被调用的。（前提是这个静态局部对象被构造过）

	//局部静态对象只会被构造一次，在调用的时候构造；在main函数执行完毕后析构

	class A
	{
	public:
		A()
		{
			cout << "A::A()" << endl;
		}
		~A()
		{
			cout << "A::~A()" << endl;
		}
		int m_i;
	};

	//void myfunc()
	const A &myfunc()
	{
		//局部静态对象
		static A s_aobj1; //不管myfunc()函数被调用几次，s_aobj1这种静态局部对象只会被构造1次（只调用一次构造函数）
		//static A s_aobj2;
		printf("s_aobj1的地址是%p\n", &s_aobj1);
		//printf("s_aobj2的地址是%p\n", &s_aobj2);
		return s_aobj1;
	}

	void func()
	{	
		myfunc();
		myfunc();
	}
}
namespace _nmsp2
{
	//二：局部静态对象数组的内存分配

	class A
	{
	public:
		A()
		{
			//cout << "A::A()" << endl;
		}
		~A()
		{
			//cout << "A::~A()" << endl;
		}
		int m_i;
	};

	void myfunc()
	{
		static A s_aobj[1000'0000]; //数组内存应该是连续的
		//for (int i = 0; i < 10000000; i++) //让编译器的分配内存优化能力失效
		//{
		//	s_aobj[i].m_i = i;
		//}
		printf("s_aobj数组的首地址是%p\n", s_aobj);

	}

	void func()
	{
		myfunc();
		myfunc();
	}
}

int main()
{	
	//_nmsp1::func();	
	_nmsp2::func();

	while (1)
	{

	}

	return 1;
}



