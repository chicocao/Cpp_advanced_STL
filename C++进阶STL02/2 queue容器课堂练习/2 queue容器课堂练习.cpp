#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>

using namespace std;

void test1()
{
	queue<int> q;
	q.push(1);
	q.push(3);
	q.push(2);
	cout << q.front() << endl;

	q.pop();
	cout << q.front() << endl;
	queue<int> q2(q);//øΩ±¥ππ‘Ï
}
int main(void)
{
	test1();
}