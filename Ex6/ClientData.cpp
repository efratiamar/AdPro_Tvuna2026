////////////////////////////////////////
#include "ClientData.h"

ClientData::ClientData(int accountNum, string Name, double Balance)
{
	setAccountNumber(accountNum);
	setName(Name);
	setBalance(Balance);
}

void ClientData::setAccountNumber(int n)
{
	accountNumber = n;
}

int ClientData::getAccountNumber() const
{
	return accountNumber;
}

void ClientData::setName(string Name)
{
	strcpy(name, Name.c_str());
}

string ClientData::getName() const
{
	return name;
}
void ClientData::setBalance(double balanceValue)
{
	balance = balanceValue;
}

double ClientData::getBalance() const
{
	return balance;
}

ostream& operator<<(ostream& os, ClientData& client)
{
	os << client.accountNumber << '\t' << client.name << '\t' << client.balance << '\n';
	return os;
}
