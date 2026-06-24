#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// EmailAddress.h
class EmailAddress {
private:
    string address;
    static fstream file;		//in EmailAddress.h
    void setAddress(string e);	//מתודת עזר שמקבלת מחרוזת 
    //ובמידה והיא כתובת תקינה מציבה אותה בתוך השדה address//	


public:
    bool uniqueAddress(string eu);
    void AddToAddressBook();
    friend istream& operator>>(istream& is, EmailAddress& e);
};

// EmailAddress.cpp

fstream EmailAddress::file;	 //איתחול ב- EmailAddress.cpp

void EmailAddress::setAddress(string e)
{
    int pos = e.find('@');
    if (pos == -1)
        throw "email address must include '@'";
    if (pos == 0)
        throw "email address cannot begin with '@'";
    string domain = e.substr(pos + 1, e.length());
    pos = domain.find('@');
    if (pos != -1)
        throw "'@' can appear only once";
    pos = domain.find('.');
    if (pos == -1) throw "domain must include at least one '.'";
    if (pos == 0)throw "domain cannot begin with '.'";
    if (domain[domain.length() - 1] == '.')throw "domain cannot end with '.'";
    
    if (uniqueAddress(e))
        address = e;
    else
        throw "address already exists";
}

bool EmailAddress::uniqueAddress(string eu)
{
    file.open("addressBook.txt", ios::in);
    if (!file)
        return false;
    bool found = false;
    string email;
    file >> email;
    while (!file.eof())
    {
        if (email == eu)
        {
            if (found == false)
                found = true;
            else
            {
                file.close();
                return false;
            }
        }

        file >> email;
    }

    file.close();
    return found;
}
void EmailAddress::AddToAddressBook()
{
    if (!uniqueAddress(address))
        return;

    file.open("addressBook.txt", ios::out);
    if (!file)
        return;

    file.seekp(ios::end);
    file << address;
    file.close();
}


istream& operator>>(istream& is, EmailAddress& e)
{
    string email;
    is >> email;
    e.setAddress(email);
    return is;
}


int main()
{
    bool flag = true;
    EmailAddress e1;
    cout << "enter an email address:\n";
    while (flag)
    {
        try {
            cin >> e1;
            flag = false;
            e1.AddToAddressBook();
        }
        catch (const char* msg)
        {
            cout << msg << endl;
            cout << "try again:\n";
        }
    }
}
