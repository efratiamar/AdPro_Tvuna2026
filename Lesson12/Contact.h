#pragma once
#include <string>
using namespace std;

class Contact
{
public:
	string name;
	string phone;
	Contact(string n, string p) : name(n), phone(p) {};

	bool operator<(const Contact& other) const
	{
		return name < other.name;
	}

	bool operator==(const Contact& other) const
	{
		return name == other.name;
	}
};
