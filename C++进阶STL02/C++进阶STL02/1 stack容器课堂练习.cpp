#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stack>
using namespace std;
//stack容器基本操作

//还可以存指针和自定义类型
void test1()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top()<<endl;
	stack<int> s2(s);//拷贝构造函数
	stack<int> s3 = s;//拷贝构造函数
	cout << s3.top() << endl;
	if (s3.empty())
	{
		cout << "s3为空" << endl;

	}
	else
	{
		cout << "s3不为空" << endl;
	}
	while (!s3.empty())
	{
		int val = s3.top(); // top返回栈顶元素
		cout << val << " ";
		s3.pop();
	}
}
int main(void)
{
	test1();
	return 0;
}