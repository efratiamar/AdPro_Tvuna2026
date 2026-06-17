#pragma once
#include "BA.h"

class MA : public BA
{
private:
	bool isParticipant;
public:
	MA();
	MA(const MA& other);
	
	bool getIsParticipant() const;
	
	void setIsParticipant(bool isP);

	bool milga() const override;
	void input(ifstream& fin) override;
	void print() const override;
	string studType() const override;
};