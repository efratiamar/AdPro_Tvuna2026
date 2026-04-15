#include <string>
#include <iostream>
using namespace std;
#include "MyString.h"

string crypto(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		char ch = str.at(i);
		if (ch >= 'a' && ch <= 'z')
			str[i] = 'z' - (ch - 'a');
	}
	return str;
}


string reverseWords(string str)
{
	string str2;
	int wordBegin = 0;
	int wordEnd;
	while ((wordEnd = str.find(" ", wordBegin)) != -1)
	{
		string word;
		for (int i = wordEnd; i >= wordBegin; i--)
			word.push_back(str[i]);
		str2 += word;
		wordBegin = wordEnd + 1;
	}
	string word = " ";
	for (int i = str.length() - 1; i >= wordBegin; i--)
		word.push_back(str[i]);
	str2 += word;

	return str2;

}

int main()
{
	MyString ms("abc dkfbd &*R#*");

	MyString ms2;

	ms2 = ms;

	if (ms2 < ms)
	{

	}

	ms2 = ms2 + ms;

	string s1 = "fffffff dsgsdgs";
	cout << s1.at(5);

	cout << s1[3];






}


