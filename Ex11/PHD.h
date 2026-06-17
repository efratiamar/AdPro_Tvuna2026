#pragma once
#include "Student.h"

class PHD : public Student
{
private:
	int resHours;
public:
	PHD();
	PHD(const PHD& other);
	//~PHD();

	int getResearchHours() const;

	void setResearchHours(int _num);

	bool milga() const override;
	void input(ifstream& fin) override;
	void print() const override;
	string studType() const override;
	bool operator<(const Student& other) const override;
};