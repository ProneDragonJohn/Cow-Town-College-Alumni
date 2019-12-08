// HTMLTable.h
#pragma once
// Demonstrates use of class to put tabluar data on the Internet
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
// Convenience class used by HTMLTable class to convert an array of strings into
// a vector of strings. Array of strings must be (sentinel)-terminated by a string of length 0.
class StringVector : public vector<string>
{
public:
	StringVector(string s[])
	{
		for (int k = 0; s[k].length() != 0; k++)
			this->push_back(s[k]);
	}
};
// This class allows a 2-dimensional table expressed as a vector of a vector of strings to
// be transformed into HTML form, a 2-d array
class HTMLTable
{
private:
	vector<string> title, headers;
	vector<vector<string> > rows;
	// Helper method for writing an HTML row in a table
	void writeRow(ostream &out, string tag, vector<string> row);
public:
	void setTitle(const vector<string> &title)
	{
		this->title = title; // Set the Title for the table
	}
	void setHeaders(const vector<string> &headers)
	{
		this->headers = headers; // Set headers for the table columns
	}
	void addRow(const vector<string> &row)
	{
		rows.push_back(row); // Add rows to table
	}
	// Write the table into HTML form into an output stream
	friend ostream &operator<<(ostream &out, HTMLTable htmlTable);
};