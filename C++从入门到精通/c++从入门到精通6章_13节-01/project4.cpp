// project4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <thread>
#include <list>
#include <mutex>
#include <future>

using namespace std;

class A {
public:
	atomic<int> atm;
	A()
	{
		atm = 0;
		//auto atm2 = atm; //这种定义时初始化操作不允许，显示 “尝试引用已删除的函数”编译器内部肯定把拷贝构造函数给干掉了用 = delete
		//atomic<int> atm3 = atm;
		//atomic<int> atm2;
		//atm2 = atm; //尝试引用已删除的函数，拷贝赋值运算符也不让用
		//load()：以原子方式读atomic对象的值
		atomic<int> atm2(atm.load()); //读
		auto atm3(atm.load());
		//store()以原子方式写入内容
		atm2.store(12);
		atm2 = 12;

	}

	void outMsgRecvQueue()
	{
		//int command = 0;
		//while (true)
		//{
		//	std::unique_lock<std::mutex> sbguard1(my_mutex1); //临界进去
		//	my_cond.wait(sbguard1, [this] {  //this，可以参考 未归类知识点，第八节
		//		if (!msgRecvQueue.empty())
		//			return true; // 该lambda返回true，则wait就返回，流程走下来，互斥锁被本线程拿到。
		//		return false; //解锁并休眠，卡在wait等待被再次唤醒
		//	});
		//	//现在互斥锁锁着，流程走下来了，队列里有数据;
		//	command = msgRecvQueue.front(); //返回第一个元素，但不检查元素是否存在；
		//	msgRecvQueue.pop_front();  //移除第一个元素，但不返回；
		//	sbguard1.unlock(); //因为unique_lock的灵活性，我们可以随时unlock解锁，以免锁住太长时间
		//	cout << "outMsgRecvQueue()执行，取出一个元素" << command << endl;
		//} //end while
		while (true)
		{
			cout << atm << endl; //读atm是个原子操作，但是整个这一行代码并不是个原子操作；
		}
	}

	void inMsgRecvQueue() //unlock()
	{
		//for (int i = 0; i < 100000; ++i)
		//{
		//	cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
		//	std::unique_lock<std::mutex> sbguard1(my_mutex1);
		//	msgRecvQueue.push_back(i); //假设这个数字i就是我收到的命令，我直接弄到消息队列里边来；
		//	my_cond.notify_one();   //我们尝试把wait()的线程唤醒，其实现在outMsgRecvQueue()中的my_cond.wait()已经醒了,但光醒了没有用，你这里要是不把互斥量撒开，醒了他也要堵在另外一个线程的wait()那里；
		//}
		for (int i = 0; i < 1000000; ++i)
		{
			atm += 1; //原子操作
			//atm = atm + 1; //不是原子操作
		}
		return;
	}

private:
	std::list<int> msgRecvQueue; //容器(消息队列)，专门用于代表玩家给咱们发送过来的命令。
	std::mutex my_mutex1; //创建了一个互斥量 （一把锁头）	
	std::condition_variable my_cond; //生成一个条件对象

};

int main()
{
	//一：补充一些知识点
	//（1.1）虚假唤醒:wait中要有第二参数(lambda)并且这个lambda中要正确判断要处理的公共数据是否存在；
	//wait(),notify_one(),notify_all()

	//（1.2）atomic ,10,11节都有介绍

	//二：浅谈线程池
	//（2.1）场景设想
	//服务器程序，--》客户端， 每来 一个客户端，就创建 一个新线程为该客户提供服务。
	//a)网络游戏，2万玩家不可能给每个玩家创建个新线程,此程序写法在这种场景下不通；
	//b)程序稳定性问题：编写的代码中，偶尔创建一个线程这种代码，这种写法，就让人感到不安；
	//线程池：把一堆线程弄到一起，统一管理。这种统一管理调度，循环利用线程的方式，就叫线程池；
	//（2.2）实现方式
	//在程序启时，我一次性的创建好一定数量的线程。10，8，100-200,更让人放心，觉得程序代码更稳定；

	//三：线程创建数量谈
	//（3.1）线程开的数量极限问题，2000个线程基本就是极限；再创建线程就崩溃；
	//（3.2）线程创建数量建议
	//a)采用某些技术开发程序；api接口提供商建议你 创建线程数量 = cpu数量，cpu *2 ,cpu *2 +2，遵照专业建议和指示来，专业意见确保程序高效率执行
    //b)创建多线程完成业务； 一个线程等于一条执行通路； 100要堵塞充值，我们这里开110个线程，那是很合适的；
	//c)1800个线程，建议，线程数量尽量不要超过500个，能控制在200个之内；


	//四：c++11多线程总结
	//windows,linux;




















	A myobja;
	std::thread myOutnMsgObj(&A::outMsgRecvQueue, &myobja); //第二个参数是 引用，才能保证线程里 用的是同一个对象。
	std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
	std::thread myInMsgObj2(&A::inMsgRecvQueue, &myobja);
	myInMsgObj.join();
	myOutnMsgObj.join();
	myInMsgObj2.join();




	//int abc = 10'00; c++新标准允许这么写
	return 0;
}
