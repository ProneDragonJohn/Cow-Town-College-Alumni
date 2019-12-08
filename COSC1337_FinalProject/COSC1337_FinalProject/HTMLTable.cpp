// HTMLTable.cpp
// Demonstrates the use of class
// to put tabular data on the Internet
#include "stdafx.h"
#include "HTMLTable.h"
/****************************************************************
* Writes a row of the table, using the given tag for th table
* data. the tag may be td for table data or th for table header.
****************************************************************/
void HTMLTable::writeRow(ostream &out, string tag, vector<string> row)
{
	out << "<tr>\n";
	for (unsigned int k = 0; k < row.size(); k++)
	{
		out << "<" << tag << "> "
			<< row[k] << " </" << tag << "> ";
	}
	out << "\n</tr>\n";
}

/***************************************************************
* Overloaded stream output operator <<
****************************************************************/
ostream & operator<<(ostream &out, HTMLTable htmlTable)
{
	out << "<table border = \"1\">\n";
	// Write the title
	string sTitleTag; // create special tag for title format
	sTitleTag = "th colspan=\""
		+ to_string(htmlTable.headers.size())
		+ "\"\n";
	htmlTable.writeRow(out, sTitleTag.c_str(), htmlTable.title);

	// Write the headers
	htmlTable.writeRow(out, "th", htmlTable.headers);
	// Write the rows of the table
	for (unsigned int r = 0; r < htmlTable.rows.size(); r++)
	{
		htmlTable.writeRow(out, "td", htmlTable.rows[r]);
	}
	// Write end tag for table
	out << "</table>\n";
	return out;
}