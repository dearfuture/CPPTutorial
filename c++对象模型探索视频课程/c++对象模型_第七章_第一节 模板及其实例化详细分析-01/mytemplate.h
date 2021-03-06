#ifndef __MYTEMPLATE__
#define __MYTEMPLATE__

#include <iostream>
using namespace std;

template<class T>
class ATPL
{
public:
	T m_i, m_j;
	ATPL(T tmpi = 0, T tmpj = 0) //构造函数
	{
		m_i = tmpi;
		m_j = tmpj;
	}

	enum ECURRSTATUS
	{
		E_CS_Busy,
		E_CS_Free,
	};

	static int m_sti;

	static T m_sti2;

	void func1() const { cout << "func1()" << endl; }
	void func2() const { cout << "func2()" << endl; }

	virtual void virfunc1()  { cout << "virfunc1()" << endl; } 
	virtual void virfunc2()  { cout << "virfunc2()" << endl; }

};
template <class T> 	int ATPL<T>::m_sti = 10;
template <class T> 	T ATPL<T>::m_sti2 = 11;

#endif