#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
using namespace std;
int main(void)
{
	string email = "zhaosi@qq.com";
	int pos1 = email.find("@");
	cout << "pos1:" << pos1 << endl;
	int pos2 = email.find(".");
	if (pos1 == -1 || pos2 == -1) {
		cout << "邮箱中不包含@或者.!" << endl;
		return 0;
	}
	if (pos1 > pos2) {
		cout << "输入的邮箱不合法！" << endl;
	}
	string username = email.substr(0, pos1);
	string::iterator pStart = username.begin();
	string::iterator pEnd = username.end();
	while (pStart != pEnd)
	{
		if (*pStart < 97 || *pStart > 122)
		{
			cout << "输入的字符包含非小写字符!" << endl;
		}
		pStart++;
	}
	string rightEmail = "zhaosi@qq.cn";
	int ret = email.compare(rightEmail);
	if (ret != 0) {
		cout << "邮箱地址不存在!" << endl;
		return 0;
	}

	cout << "邮箱地址正确!" << endl;
	cout << username << endl;
	return 0;
}