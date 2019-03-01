// project100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <time.h >
#include <stdio.h>
using namespace std;

//class FAC //父类
//{
//public:
//	int m_fai;
//	int m_faj;
//};
//class MYACLS :public FAC //子类
//{
//public:
//	int m_i;
//	int m_j;
//};

//class Base //sizeof = 8字节；
//{
//public:
//	int m_i1;
//	char m_c1;
//	char m_c2;
//	char m_c3;
//};

class Base1
{
public:
	int m_i1;
	char m_c1;
};
class Base2 :public Base1
{
public:
	char m_c2;
};
class Base3 :public Base2
{
public:
	char m_c3;
};


int main()
{		
	//第五节  单一继承下的数据成员布局
	//printf("FAC::m_fai = %d\n", &FAC::m_fai);
	//printf("FAC::m_faj = %d\n", &FAC::m_faj);

	//printf("MYACLS::m_fai = %d\n", &MYACLS::m_fai);
	//printf("MYACLS::m_faj = %d\n", &MYACLS::m_faj);
	//
	//printf("MYACLS::m_i = %d\n", &MYACLS::m_i);
	//printf("MYACLS::m_j = %d\n", &MYACLS::m_j);

	////(1)一个子类对象，所包含的内容，是他自己的成员，加上他父类的成员的总和；
	////(2)从偏移值看，父类成员先出现，然后才是孩子类成员。
	//FAC facobj;
	//MYACLS myaclobj; //子类对象中实际上是包含着父类子对象的

	/*cout << sizeof(Base) << endl;   //8字节，数据布局（内存排列上）紧凑；
	printf("Base::m_i1 = %d\n", &Base::m_i1);
	printf("Base::m_c1 = %d\n", &Base::m_c1);
	printf("Base::m_c2 = %d\n", &Base::m_c2);
	printf("Base::m_c3 = %d\n", &Base::m_c3);*/

	//引入继承关系后，可能会带来内存空间的额外增加。

	cout << sizeof(Base1) << endl; //8
	cout << sizeof(Base2) << endl; //12
	cout << sizeof(Base3) << endl; //16
	printf("Base3::m_mi1 = %d\n", &Base3::m_i1);
	printf("Base3::m_mc1 = %d\n", &Base3::m_c1);
	printf("Base3::m_mc2 = %d\n", &Base3::m_c2);
	printf("Base3::m_mc3 = %d\n", &Base3::m_c3);

	//linux上windows上数据布局不一样，说明：
	//a)编译器在不断的进步和优化；
	//b)不同厂商编译器，实现细节也不一样；
	//c)内存拷贝就要谨慎；

	Base2 mybase2obj;
	Base3 mybase3obj;
	//你就不能用memcpy内存拷贝把Base2内容直接Base3里拷贝；


	
	return 1;
}

