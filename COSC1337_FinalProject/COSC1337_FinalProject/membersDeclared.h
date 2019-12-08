#pragma once
#include "stdafx.h"
using namespace std;

class Member
{
protected:
	string Lname;
	string Fname;
	string Cname;
	string Address;
	string City;
	string State;
	string Zip;
	string Phone;
	string Email;
	static int numMembers;

public:
	Member();
	Member(string ln, string fn, string cn, string a,
			string c, string s,string z,string p,string e);
	Member(Member &obj);
	~Member();

	void setLname(string ln);
	void setFname(string fn);
	void setCname(string cn);
	void setAddress(string a);
	void setCity(string c);
	void setState(string s);
	void setZip(string z);
	void setPhone(string p);
	void setEmail(string e);

	string getLname();
	string getFname();
	string getCname();
	string getAddress();
	string getCity();
	string getState();
	string getZip();
	string getPhone();
	string getEmail();

	bool operator>(const Member &right);
	bool operator<(const Member &right);
};