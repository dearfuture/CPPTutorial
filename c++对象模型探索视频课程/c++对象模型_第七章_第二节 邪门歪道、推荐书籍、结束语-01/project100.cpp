
#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>

using namespace std;

namespace _nmsp1
{	
	//一：不能被继承的类B
	//c++11 final关键字；
	//友元函数+虚继承   = 不能被继承的类
	//副作用：友元，破坏封装性；虚继承，消耗比较大；
	class A
	{
	private:
		A() 
		{
			int abc;
			abc = 12;
		}
		friend class B;  //我们希望类B能够成为一个不能被继承的类
	};
	//class B :public A
	class B : virtual public A
	{
	public:
		int m_b;
	};

	//我希望类B不能被继承
	class C :public B
	{
	public:
		int m_c;
	};

	void func()
	{	
		//A objba; //构造函数私有，所以生成A对象不可以

		B myobjb;
		myobjb.m_b = 15;

		/*C myobjc;
		myobjc.m_c = 20;*/




		return;
	}
}
namespace _nmsp2
{
	//二：类外调用私有虚成员函数
	class A
	{
	private :
		virtual void virfunc()
		{
			myfunc();
		}
		void myfunc()
		{
			cout << "myfunc() run---------" << endl;
		}
	};

	void func()
	{
		A obj;
		//(reinterpret_cast<void(*)()>(**(int **)(&obj)))(); //调用虚函数virfunc();
		                           //无非就是走虚函数表来调用虚函数，这些知识咱们都讲过，尤其是三章二节详细写过手工调用虚函数的代码；
		long *pvptr = (long *)&obj; //把对象obj的地址拿到
		long *vptr = (long *)(*pvptr); //拿到虚函数表指针
		typedef void(*Func)(void); //定义个函数指针类型
		Func f = (Func)vptr[0]; //给虚函数表指针f赋值为第一个虚函数地址virfunc
		f(); //调用虚函数

	}
}

int main()
{	
	//_nmsp1::func();		
	_nmsp2::func();

	//四：结束语，学习之道（c++之道）
	//(1)选对老师
	//(2)走对路
	//建议：
	//(1)学精不要学杂，不要贪大求全，否则会分散精力，浪费时间
	//(2)尽早选择一条能拿高薪的路，一直不断的努力达成目的；

	//推荐三门课，不需要多学，按顺序从初级到高级，
	//《c语言入门》
	//《c++从入门到精通c++98/11/14/17》
	//《c++对象模型探索》：你是司机，你会开车了，你还会修车；
	//10-20k
	//c++开发之路刚刚开始，要选择深造的方向了；
	//图形学，游戏服务器，网络通讯架构，虚拟现实，嵌入式系统，设备驱动，音频视频，ai底层。
	//50-80K/月薪 ,网络通讯架构能够拿到这个月薪；
	//《linux c++通讯架构实战》 --30K 一年左右；






	return 1;
}



