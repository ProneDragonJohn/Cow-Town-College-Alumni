#include "stdafx.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

vector<Member> *m;

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);
	
	m = new vector<Member>;
	COSC1337_FinalProject::fmTable^ myTable = gcnew COSC1337_FinalProject::fmTable();

	int choice;
	string state;
	do
	{
		loadData();
		myTable->Close();
		displayMenu();
		cout << "\nPlease select a report you wish to be run from menu above (0-3): ";
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case 0:
			break;
		case 1:
			myTable = gcnew COSC1337_FinalProject::fmTable();
			writeTable(*m);
			myTable->Refresh();
			myTable->ShowDialog();
			break;
		case 2:
			myTable = gcnew COSC1337_FinalProject::fmTable();
			sortLname();
			writeTable(*m);
			myTable->Refresh();
			myTable->ShowDialog();
			break;
		case 3:
			vector<Member>().swap(*m);
			myTable = gcnew COSC1337_FinalProject::fmTable();
			cout << "\nWhat state do you wish to view? ";
			cin >> state;
			cout << "\n";
			loadState(state);
			sortCity();
			sortCity();
			writeTable(*m);
			myTable->Refresh();
			myTable->ShowDialog();
			break;
		}
		cout << "\n";
		vector<Member>().swap(*m);
	} while (choice != 0);

	
	return 0;
}

void displayMenu()
{
	cout << "Cow Town College Alumni Reports Menu\n"
		<< "=======================================================\n"
		<< "      1: All Members by Natural Order of Input File\n"
		<< "      2: All Members Sorted Ascending by Last Name\n"
		<< "      3: Members in One State Only, sorted Ascending by City\n"
		<< "      0: Exit the program\n";

}

void OpenFiles(ifstream &in)
{
	in.open("members.csv");
	if (!in)
	{
		cout << "Input file did not open. Program will exit." << endl;
		exit(0);
	}
}

Member readFile(string &sLine, vector<string> &sParsed, ifstream &fin)
{
	getline(fin, sLine);
	stringstream lineStream(sLine);
	string field;
	sParsed.clear();

	while (getline(lineStream, field, ','))
	{
		sParsed.push_back(field);
	}
	return Member(sParsed[0], sParsed[1], sParsed[2], sParsed[3], 
					sParsed[4], sParsed[5], sParsed[6], sParsed[7], sParsed[8]);
}

void loadData()
{
	string sFileLine;
	vector<string> sParsedLine;

	ifstream fin;
	OpenFiles(fin);

	while (!fin.eof())
		(*m).push_back(readFile(sFileLine, sParsedLine, fin));
}

void sortLname()
{
	Member *temp = new Member;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < long((*m).size() - 1); count++)
		{
			if ((*m)[count] > (*m)[count + 1])
			{
				*temp = (*m)[count];
				(*m)[count] = (*m)[count + 1];
				(*m)[count + 1] = *temp;
				swap = true;
			}
		}
	} while (swap);
	delete temp;
}

void sortCity()
{
	Member *temp = new Member;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < long((*m).size() - 1); count++)
		{
			if ((*m)[count] < (*m)[count + 1])
			{
				*temp = (*m)[count];
				(*m)[count] = (*m)[count + 1];
				(*m)[count + 1] = *temp;
				swap = true;
			}
		}
	} while (swap);
	delete temp;
}

void checkState(string &sLine, vector<string> &sParsed, ifstream &fin, string state)
{
	getline(fin, sLine);
	stringstream lineStream(sLine);
	string field;
	sParsed.clear();

	while (getline(lineStream, field, ','))
	{
		sParsed.push_back(field);
	}

	if (sParsed[5] == state)
	{
		(*m).push_back(Member(sParsed[0], sParsed[1], sParsed[2], sParsed[3],
			sParsed[4], sParsed[5], sParsed[6], sParsed[7], sParsed[8]));
	}
	else
	{
		return;
	}
}

void loadState(string state)
{
	string sFileLine;
	vector<string> sParsedLine;

	ifstream fin;
	OpenFiles(fin);

	while (!fin.eof())
	{
		checkState(sFileLine, sParsedLine, fin, state);
	}
		
}