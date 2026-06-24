#pragma once
#include <iostream>
#include <string>
using namespace std;



class Pastry
{
	float bakingTime;

public:
	Pastry(float bt) : bakingTime(bt) {};
	virtual float calcCalories() const = 0;
	void printInfo() const
	{
		cout << "BT: " << bakingTime << "Calo: " << calcCalories() << endl;
	}
};

class Cake : public Pastry
{
	int layers;
	double caloriesPerLayer;
public:
	Cake(float bt, int l, double c)
		: Pastry(bt), layers(l), caloriesPerLayer(c)
	{	}

	float calcCalories() const override
	{
		return layers* caloriesPerLayer;
	}


};

class Cookie : public Pastry
{
	float radius;
	double caloriesPerCm;
public:
	Cookie(float bt, int r, double c)
		: Pastry(bt), radius(r), caloriesPerCm(c)
	{
	}

	float calcCalories() const override
	{
		return radius * radius * 3.14 * caloriesPerCm;
	}


};

//#include "Cake.h"
//#include "Cookie.h"
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
int mainTest()
{
	list<Pastry*> pastries; // הצהרה על רשימת המאפים
	float bakeTime;
	int choice;
	cout << "Enter pastry type (1 for Cake, 2 for Cookie) or 0 to end: ";
	cin >> choice;
	while (choice) {
		switch (choice) {
		case 1:	// הוספת עוגה לרשימה

			int layers;
			float calPerLayer;
			cout << "Enter baking time(minutes), layers, calories per layer: ";
			cin >> bakeTime >> layers >> calPerLayer;

			//Pastry* p = new Cake(bakeTime, layers, calPerLayer);
			//pastries.push_back(p);
			pastries.push_back( new Cake(bakeTime, layers, calPerLayer) );
			
			//Cake c(bakeTime, layers, calPerLayer); NO!!!! XXXXXXXXXXXX
			//pastries.push_back(&c); NO!!! XXXXXXXX

			break;
		case 2: // הוספת עוגיה לרשימה

			float radius, calPerCm;
			cout << "Enter baking time(minutes), radius(cm), calories per cm area: ";
			cin >> bakeTime >> radius >> calPerCm;
			pastries.push_back(new Cookie(bakeTime, radius, calPerCm));
			break;
		default:cout << "Invalid choice, please enter 0,1 or 2.\n";
		}
		cout << "Enter pastry type (1 for Cake, 2 for Cookie) or 0 to end: ";
		cin >> choice;
	}

	//הדפסת נתוני כל המאפים
	//option A - long
	////for (list<Pastry*>::iterator it = pastries.begin(); it != pastries.end(); it++)
	//for (auto it = pastries.begin(); it != pastries.end(); it++)
	//{
	//	(*it)->printInfo();
	//}

	//option B - short
	for_each(pastries.begin(), pastries.end(), [](Pastry* p) { p->printInfo(); });

	// שחרור זיכרון שהוקצה דינאמית
	for (auto it = pastries.begin(); it != pastries.end(); it++)
	{
		if (*it)
			delete (*it);
	}

		return 0;
}


