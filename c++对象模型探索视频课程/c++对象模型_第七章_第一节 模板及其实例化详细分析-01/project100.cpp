
#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>
#include "mytemplate.h"
using namespace std;

//template class ATPL<int>;  //显式实例化语法,这种语法会把模板类的所有内容都实例化出来；
template void ATPL<int>::func2() const; //显式实例化单独的成员函数,并没有实例化出类ATPL<int>本身；


//namespace _nmsp1
//{	
//	//一：函数模板
//	//编译器编译时，根据针对funcadd()的调用来确定T的类型。
//	//如果我们并没有针对funcadd()的调用代码，那么编译器不会为我们产生任何和funcadd有关的代码，就好像函数模板funcadd()从来没存在过一样；
//
//
//	template <class T>   //针对T的类型推断，是编译器在编译的时候，根据针对funcadd()的调用来确定的
//	T funcadd(const T&a, const T& b)
//	{
//		T addhe = a + b;
//		return addhe;
//	}
//	void func()
//	{
//		cout << funcadd(12, 14) << endl; 
//
//
//		return;
//	}
//}
//namespace _nmsp2
//{
//	//二：类模板的实例化分析
//	//如果程序代码中没有用到ATPL，那么编译器对ATPL类模板视而不见，就好像从来没存在过一样；
//	//（2.1）模板中的枚举类型，和类模板本身关系不大
//	//（2.2）类模板中的静态成员变量
//	//（2.3）类模板的实例化
//	//（2.4）成员函数的实例化
//
//	template<class T>
//	class ATPL
//	{
//	public:
//		enum ECURRSTATUS
//		{
//			E_CS_Busy,
//			E_CS_Free
//		};
//	public:
//		T m_i, m_j;
//		ATPL(T tmpi = 0, T tmpj = 0) //构造函数
//		{
//			m_i = tmpi;
//			m_j = tmpj;
//		}
//
//		void func1() const { cout << "func1()" << endl; } //在不被调用的情况下不会被实例化
//		void func2() const { cout << "func2()" << endl; }
//
//
//		static int m_sti;
//		static T m_sti2;
//
//	};
//	template <class T> int ATPL<T>::m_sti = 10;
//	template <class T> T ATPL<T>::m_sti2 = 15; //这的值15是否合法取决于你将来T的类型
//
//	void func()
//	{
//		/*
//		ATPL<int>::ECURRSTATUS myenum; //注意这里加<int>
//		myenum = ATPL<int>::E_CS_Busy;
//		ATPL<int>::ECURRSTATUS myenum2;
//		myenum2 = ATPL<int>::E_CS_Free;
//
//		ATPL<double>::ECURRSTATUS myenum3;
//		myenum3 = ATPL<double>::E_CS_Free;
//		*/
//
//		/*ATPL<int>::m_sti = 18;
//		ATPL<float>::m_sti = 21;
//
//		cout << ATPL<int>::m_sti << endl;
//		cout << ATPL<float>::m_sti << endl;*/
//		
//		/*ATPL<int>::m_sti2 = 18;
//		ATPL<float>::m_sti2 = 21;
//		cout << ATPL<int>::m_sti2 << endl;
//		cout << ATPL<float>::m_sti2 << endl;*/
//
//		//ATPL<int> *pobj = NULL; //此种写法不会实例化出具体的类
//		const ATPL<int> &yobj = 0; //实例化了类模板
//		yobj.func1();
//
//		//ATPL<int> tmpobj(0);
//		//const  ATPL<int> &yobj = tmpobj;
//
//
//
//
//	}
//}
namespace _nmsp3
{
	//三:多个源文件中使用类模板
	//在多个obj文件中可能产生多个重复的类模板对应的具体的实例化类，但链接的时候只会保留一个ATPL<int>类的实体，其余的会被忽略掉；
	//（3.1）虚函数的实例化
	//虚函数即使没有被调用，但也会被实例化出来，为什么？因为有虚函数，编译器就会产生虚函数表。虚函数表里是各个虚函数的地址，既然需要各个虚函数的地址，那么必须要实例化每个虚函数出来。
	//（3.2）显式实例化

	void myfunc()
	{
		/*ATPL<int> myobj;
		myobj.m_sti2 = 18;
		cout << myobj.m_sti2 << endl;*/
	}

	void func()
	{


	}
}


int main()
{	
	//_nmsp1::func();		
	//_nmsp2::func();
	_nmsp3::func();

	return 1;
}



