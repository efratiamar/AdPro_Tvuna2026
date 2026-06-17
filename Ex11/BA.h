#pragma once
#include "Student.h"

class BA : public Student
{
private:
	int* grades;
	int size;
public:
	BA();
	BA(const BA& other);	
	BA(BA&& other);
	~BA();
	BA& operator=(const BA& other);
	BA& operator=(BA&& other);

	
	int* getGrades() const;
	int getSize() const;
	
	void setGrades(int* pg);
	void setSize(int s);

	bool milga() const override;
	void input(ifstream& fin) override;
	void print() const override;
	double average() const;
	string studType() const override;
	bool operator<(const Student& other) const override;
};