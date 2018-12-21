#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

void test1() {
	//容器
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);

	//迭代器
	vector<int>::iterator pStart = v.begin();//拿到了指向第一个元素的迭代器

	vector<int>::iterator pEnd = v.end();//返回指向最后一个元素下一个位置
	while (pStart != pEnd)
	{
		cout << *pStart << endl;
		pStart++;
	}
	int n = count(v.begin(), v.end(), 3);
	cout << "n=" << n << endl;
}

class Teacher {
public:
	Teacher(int id, int age) :ID(id), age(age) {}
	int ID;
	int age;
};

void test2()
{
	vector<Teacher> v;
	Teacher t1(1, 1);
	Teacher t2(2, 2);
	Teacher t3(3, 3);
	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);

	vector<Teacher>::iterator pStart = v.begin();
	vector<Teacher>::iterator pEnd = v.end();
	while (pStart != pEnd)
	{
		cout << (*pStart).age<<"  "<< (*pStart).ID<< endl;
		pStart++;
	}
}
//容器放类对象指针
void test3() {

	vector<Teacher*> v; //容器中放Teacher类型指针
	Teacher t1(1, 2), t2(3, 4), t3(5, 6);

	Teacher* p1 = &t1;
	Teacher* p2 = &t2;
	Teacher* p3 = &t3;

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	vector<Teacher*>::iterator pStart = v.begin(); //指向第一个元素的迭代器
	vector<Teacher*>::iterator pEnd = v.end();

	while (pStart != pEnd) {
		Teacher* ttemp = *pStart;
		cout << ttemp->ID << " " << ttemp->age << endl;
		pStart++;
	}
	cout << endl;

}

int main(void)
{
	//test1();
	//test2();
	test3();
}