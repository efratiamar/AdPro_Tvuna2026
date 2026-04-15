#pragma once

class MyString
{
	char* str;
public:
	MyString(const char* s = nullptr);
	MyString(const MyString& other);
	~MyString();

	char* getString() const;
	int length() const;
	void print() const;

	MyString& operator=(const MyString& other);

	bool operator==(const MyString& other) const;
	bool operator!=(const MyString& other) const;
	bool operator<(const MyString& other) const;
	bool operator>(const MyString& other) const;


	MyString operator+(const MyString& other) const;
	MyString operator*(const int num);

};
