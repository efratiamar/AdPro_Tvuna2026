#include "MyString.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

MyString::MyString(const char* s)
{
	str = new char[strlen(s)];
	strcpy(str, s);
}

MyString::MyString(const MyString& other)
{
	str = new char[strlen(other.str)];
	strcpy(str, other.str);

}

MyString::~MyString()
{
	if (str)
		delete [] str;
}

char* MyString::getString() const
{
	return str;
}

int MyString::length() const
{
	return strlen(str);
}

void MyString::print() const
{
	cout << str;
}

MyString& MyString::operator=(const MyString& other)
{
	if (str)
		delete[] str;

	str = new char[strlen(other.str)];
	strcpy(str, other.str);

	return *this;

}

bool MyString::operator==(const MyString& other) const
{
	return strcmp(str, other.str) == 0;
}

bool MyString::operator!=(const MyString& other) const
{
	return strcmp(str, other.str) != 0;
}

bool MyString::operator<(const MyString& other) const
{
	return (strcmp(str, other.str) < 0);
}

bool MyString::operator>(const MyString& other) const
{
	return (strcmp(str, other.str) > 0);
}

MyString MyString::operator+(const MyString& other) const
{
	int sizeI = strlen(str);
	int sizeII = strlen(other.str);
	char* temp = new char[sizeI + sizeII + 1];
	strcpy(temp, str);
	strcpy(temp + sizeI, other.str);
	MyString x(temp);
	return x;
}

MyString MyString::operator*(const int num)
{
	char* temp;
	int len = strlen(str);
	temp = new char[len * num + 1];
	for (int i = 0; i < num; i++)
		strcpy(temp + i * len, str);
	MyString s(temp);
	return s;
}



