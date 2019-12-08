#pragma once
#include "stdafx.h"



int main();

void displayMenu();
void OpenFiles(ifstream &in);
Member readFile(string &sLine, vector<string> &sParsed, ifstream &fin);
void loadData();
void sortLname();
void sortCity();
void checkState(string &sLine, vector<string> &sParsed, ifstream &fin, string state);
void loadState(string state);