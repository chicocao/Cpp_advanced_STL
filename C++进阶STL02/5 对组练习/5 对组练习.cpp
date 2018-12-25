#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
int main(void)
{

	//第一种方式 创建一个pair
	pair<int, string> mypair(10, "abv");
	cout << mypair.first << endl;
	cout << mypair.second << endl;
	//第二种方式 创建一个pair
	pair<int, string> mypair2 = make_pair(10, "abc");
	//不知道make_pair返回什么类型的，就指定为auto，自动指定类型
	//auto mypair2 = make_pair("aaa", "bbb");
	cout << mypair2.first << " " << mypair2.second << endl;
	//第三种 
	pair<int, string> mypair3 = mypair; //拷贝构造
}