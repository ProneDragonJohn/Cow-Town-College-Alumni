#include "stdafx.h"
#include "membersDeclared.h"

int Member::numMembers = 0;

Member::Member()
{
	Lname = "";
	Fname = "";
	Cname = "";
	Address = "";
	City = "";
	State = "";
	Zip = "";
	Phone = "";
	Email = "";
}
Member::Member(string ln, string fn, string cn, string a,
				string c, string s, string z, string p, string e)
{
	Lname = ln;
	Fname = fn;
	Cname = cn;
	Address = a;
	City = c;
	State = s;
	Zip = z;
	Phone = p;
	Email = e;
	numMembers++;
}
Member::Member(Member &obj)
{
	Lname = obj.Lname;
	Fname = obj.Fname;
	Cname = obj.Cname;
	Address = obj.Address;
	City = obj.City;
	State = obj.State;
	Zip = obj.Zip;
	Phone = obj.Phone;
	Email = obj.Email;
	obj.numMembers++;
}
Member::~Member()
{
	numMembers--;
}

void Member::setLname(string ln)
{
	Lname = ln;
}
void Member::setFname(string fn)
{
	Fname = fn;
}
void Member::setCname(string cn)
{
	Cname = cn;
}
void Member::setAddress(string a)
{
	Address = a;
}
void Member::setCity(string c)
{
	City = c;
}
void Member::setState(string s)
{
	State = s;
}
void Member::setZip(string z)
{
	Zip = z;
}
void Member::setPhone(string p)
{
	Phone = p;
}
void Member::setEmail(string e)
{
	Email = e;
}

string Member::getLname()
{
	return Lname;
}
string Member::getFname()
{
	return Fname;
}
string Member::getCname()
{
	return Cname;
}
string Member::getAddress()
{
	return Address;
}
string Member::getCity()
{
	return City;
}
string Member::getState()
{
	return State;
}
string Member::getZip()
{
	return Zip;
}
string Member::getPhone()
{
	return Phone;
}
string Member::getEmail()
{
	return Email;
}

bool Member::operator>(const Member &right)
{
	if (this->Lname > right.Lname)
		return true;
	else
		return false;
}

bool Member::operator<(const Member &right)
{
	if (this->City > right.City)
		return true;
	else
		return false;
}