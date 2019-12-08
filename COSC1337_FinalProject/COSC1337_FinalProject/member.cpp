#include "stdafx.h"

void writeTable(vector<Member> &sArray)
{
	// Hard-coded data for the title and headings of the table
	// The array must have 1 empty string literal at end
	// which is the "sentinal" record to stop the class' write loop
	string sTitle[] = { "Cow Town College Alumni", "" };
	string sHeaders[] = { "Last Name", "First Name", "Company", "Address",
		"City", "State", "Zip", "Phone", "Email", "" };

	// Create the HTML table object and set its members
	HTMLTable hTable;
	hTable.setTitle(StringVector(sTitle));
	hTable.setHeaders(StringVector(sHeaders));

	// Loop to create table rows from array data
	// The array must have empty string sentinels
	int arraySize = sArray.size();
	for (int i = 0; i < arraySize; i++)
	{
		string row[] = { sArray[i].getLname(),
			sArray[i].getFname(),
			sArray[i].getCname(),
			sArray[i].getAddress(),
			sArray[i].getCity(),
			sArray[i].getState(),
			sArray[i].getZip(),
			sArray[i].getPhone(),
			sArray[i].getEmail(),
		""}; // Sentinal string
		hTable.addRow(StringVector(row));
	}
	// Open a new HTML file for the table
	ofstream fout("c:\\temp\\AlumniTable.html");
	if (!fout)
	{
		cout << "Output Table file did not open. Program will exit."
			<< endl;
		exit(0);
	}
	// Write the HTML code to the file
	fout << hTable;
	fout.close(); // close the file
}