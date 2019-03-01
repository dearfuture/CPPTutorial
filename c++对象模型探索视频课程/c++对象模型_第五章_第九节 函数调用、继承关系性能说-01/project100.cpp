
#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

namespace _nmsp1 //命名空间
{
	//一：函数调用中编译器的循环代码优化	
	//debug,release
	//（1）优化循环，把循环优化成1条语句；
	//（2）在编译期间，编译器也具有运算能力，有些运算编译器在编译期间就能搞定；

	__int64 mytest(int mv)
	{		
		__int64 icout = 0;
		for (int i = 1; i < 1000000; i++)
		{
			icout += 1;
			if (i == 10000 && mv == 999)
			{
				printf("------\n");
			}
		}
		//icout += 循环多少次之后的和值
		return icout;
	}

	void func()
	{
		clock_t start, end;
		__int64 mycout = 1;
		start = clock();
		for (int i = 0; i <= 1000; i++)
		{
			//mycout += mytest(i); //给固定参数时，编译器将这种参数固定的函数调用视为一种不变的表达式
			mycout += mytest(6);
		}
		//mycout += 循环1000次的和值
		end = clock();
		cout << " 用时(毫秒）：" << end - start << endl;
		cout << " mycout:" << mycout << endl;		
	}
}
namespace _nmsp2
{

	//二：继承关系深度增加，开销一般也会增加
	//很多情况下，锁着继承深度的增加，开销或者说执行时间也会增加；
	//（2.1）多重继承一般也会导致开销增加

	class A
	{
	public:
		A()
		{
			cout << "A::A()" << endl;
		}
	};
	class A1
	{
	public:
		A1()
		{
			cout << "A1::A1()" << endl;
		}
	};

	class B :public A,public A1
	{
	public:
	};
	class C :public B
	{
	public:
		C()
		{
			cout << "C::C()" << endl;
		}
	};
	void func()
	{
		C cobj;

	}
}
namespace _nmsp3
{
	//三：继承关系深度增加，虚函数导致的开销增加
	class A
	{
	public:
		/*A()
		{
			cout << "A::A()" << endl;
		}*/
		virtual void myvirfunc() {}
	};	

	class B :public A
	{
	public:
	};
	class C :public B
	{
	public:
		C()
		{
			cout << "C::C()" << endl;
		}
	};

	void func()
	{
		C *pc = new C();


	}
}

int main()
{
	//_nmsp1::func();
	//_nmsp2::func();
	_nmsp3::func();
	return 1;
}



