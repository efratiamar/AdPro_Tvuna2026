#include"BA.h"
#include"MA.h"
#include"PHD.h"
#include<algorithm>
#include<iostream>
#include<fstream>
#include<list>

using namespace std;
enum option {
	stop,			//	סיום התוכנית
	addNewStudent,	//	הוספת סטודנט חדש
	printAllSudnets,	//	הדפסת פרטי כל הסטודנטים ברשימה
	milgaList,		//	הדפסת מספר זהות ושם הזכאים למלגה
	countMilgaBA,	//	מספר הסטודנטים לתואר ראשון הזכאים למלגה
	noResearchMA,	//	הדפסת נתוני הסטודנטים לתואר שני שאינם חוקרים
	overheadStudent,	//	האם קיים סטודנט שלומד יותר מ- 15 קורסים
	allGraduate,		//	בדיקה האם כל הסטודנטים זכאים לתעודת גמר
	removePHDFailers,	//	מחיקת כל הסטודנטים לתואר שלישי שאינם לומדים קורסים

};

Student* addStudent(ifstream& is);

int menu()
{
	int choice;
	do {
		cout << "enter 0 to stop\n";
		cout << "enter 1 to add a new student\n";
		cout << "enter 2 to print all students detail\n";
		cout << "enter 3 to print detail of milga studnets\n";
		cout << "enter 4 to count #BA studnets for milga\n";
		cout << "enter 5 to print id and name of non research MA students \n";
		cout << "enter 6 to check if there is a student that takes more than 15 courses\n";
		cout << "enter 7 to check if all students can graduate\n";
		cout << "enter 8 to remove from list all Phd students with no courses at all\n"; 	//	
		cin >> choice;
	} while (choice<stop || choice>removePHDFailers);
	return choice;

}
int main()
{
	ifstream is("students.txt");
	if (!is)
		throw "cannot open students file";
	//	הצהרה על רשימה של סטודנטים
	// _______________________________
	list<Student*> ls;

	int op;
	op = menu();
	while (op != stop) {
		switch (op) {
		case addNewStudent: //הוספת סטודנט חדש 
		{	
			// _______________________________
			ls.push_back( addStudent(is) );
			break;
		}
		case printAllSudnets: //הדפסת נתוני כל הסטודנטים ברשימה
		{
			//______________________________________________
			for_each(ls.begin(), ls.end(), [](Student* ps) { ps->print(); });
			break;
		}
		case milgaList: //הדפסת מספר זהות ושמות הזכאים למלגה 				
		{
			//______________________________________________
			for_each(ls.begin(), ls.end(),
				[](Student* ps)
				{
					if (ps->milga())
						cout << ps->getId() << " " << ps->getFirstName() << endl;
				}
			);

			break;
		}
		case countMilgaBA: //הדפסת כמות הזכאים למלגה בתואר הראשון
		{
			cout << "#BA studnets for milga: ";
			// cout<<_______________________________________

			cout << count_if(ls.begin(), ls.end(),[](Student* ps){return ps->milga();}) << endl;
			break;
		}
		case noResearchMA: //הדפסת ת.ז ושמות סטודנטים לתואר שני שאינם חוקרים 
		{
			cout << "list of no research MA students : \n";
			//______________________________________________
			for_each(ls.begin(), ls.end(), [](Student* ps)
				{
					if (ps->studType() == "MA" && !((MA*)ps)->getIsParticipant())
						cout << ps->getId() << " " << ps->getFirstName() << endl;
				});
			break;
		}
		case overheadStudent: //האם קיים סטודנט שלומד יותר מ - 15 קורסים
		{
			//if (//________________________________________)
			cout << any_of(ls.begin(), ls.end(),
				[](Student* ps) { return ps->getNumberOfCourses() > 15; }) << endl;
			break;
		}
		case allGraduate: //האם כל הסטודנטים זכאים לתעודת גמר
			//זכאים סטודנטים עם ממוצע מעל 55 או 20 שעות מחקר						
		{
			//if (//________________________________________)
			if (
				all_of(ls.begin(), ls.end(), [](Student* ps)
					{
						if (ps->studType() == "PhD" && ((PHD*)ps)->getResearchHours() >= 20)
							return true;
						else if (ps->studType() != "PhD" && ((BA*)ps)->average() > 55)
							return true;
						else
							return false;
					})
				)
				cout << "all students can graduate\n";
			else
				cout << "not all students can graduate\n";

			break;
		}
		case removePHDFailers:
			//מחיקת את כל הסטודנטים לתואר שלישי שאינם לומדים קורסים בכלל
			//______________________________________________
			// הדפסת הרשימה שלאחר המחיקה
			//______________________________________________
		{
			auto newEnd = remove_if(ls.begin(), ls.end(), [](Student* ps)
				{
					return ps->studType() == "PhD" && ps->getNumberOfCourses() == 0;
				});

			//option 1
			//for_each(ls.begin(), newEnd, [](Student* ps) {ps->print(); });
			//option 2 - better
			ls.erase(newEnd, ls.end());
			for_each(ls.begin(), ls.end(), [](Student* ps) {ps->print(); });

			break;
		}
		};
		op = menu();
	}
	is.close();
	return 0;
}

Student* addStudent(ifstream& is) {
	Student* s = nullptr;
	cout << "Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish" << endl;
	int choice;
	is >> choice;
	switch (choice)
	{
	case 1: s = new BA();
		break;
	case 2: s = new MA();
		break;
	case 3: s = new PHD();
		break;
	case 0: return nullptr;
		break;
	default: throw "no such degree";
	}
	s->input(is);
	return s;
}
