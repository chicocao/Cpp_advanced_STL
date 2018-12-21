#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//char* 和 string转换
void test1() {
	//string类型转换为char*字符串
	string s1 = "abcdefg";
	string snull;


	//cout << s2 << endl;

	const char *c2 = s1.c_str();
	cout << c2 << endl;

	//char*类型字符串转换为string类型字符串

	char * c1 = (char*) "fsdjl";

	string s2(c1);
	
}

//string初始化
void test2()
{
	string s1;//默认构造
	string s2 = "fsa";
	string s3(s2);
	string s4(4, 'a');

}
//string容器字符串赋值和存取
void test3() {
	string s1 = "abcdefg";
	char a = s1[2];
	cout << a;
	char b = s1.at(2);//会抛异常
	cout << b;
	

}
//string容器拼接操作
void test4()
{
	string s1 = "aaa";
	string s2 = "bbb";
	string s3 = s1 + s2;
	cout << s3 <<endl;
	s3.append(s1);
	cout << s3 << endl;
}
//string查找和替换 比较
void test5()
{
	string s = "acbdefg";
	int n = s.find("b");
	int m = s.rfind("b");
	cout << n << endl;
	cout << m << endl;
	s.replace(0, 4, "4");
	cout << s << endl;
}
//string 比较 子串 插入和删除
void test6()
{

	//比较
	string s1 = "abc";
	string s2 = "abd";
	int result = s1.compare(s2);
	cout << result << endl;
	string s3 = "abcdefghijklmnopq";
	string s4 = s3.substr(0, 3);
	cout << s4 << endl;
	s3.insert(s3.size(), "xyz");
	cout << s3<<endl;
	s3.erase(0, 4);
	cout << s3;

}
int main(void)
{
	test5();

}