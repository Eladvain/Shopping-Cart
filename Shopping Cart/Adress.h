#ifndef _AD_H
#define _AD_H 
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
class adress
{
public :
	friend class user;
	adress() = default;
	//~adress() is not needed becouse we dont have any dynamic allocation int that class
	adress(const string&city, const string& street, const int&  houseNumber);// constructor
	adress(const adress& other);//copy constructor
	static const int MAX_LENGTH_CITY_STREET = 26;
	bool A_checkValidity(const string& city, const string& street, const int&  houseNumber);// check if the input is val
	void A_setCity(const string &city);
	void A_setStreet(const string& street);
	void A_setHouseNumber(const int& num);
	void A_adressPrint()						const;
	string A_getcity()						const;
	string A_getStreet()					const;
	const int& A_getNumber()					const;
	friend ostream& operator<<(ostream& os, const adress& ad)
	{
		if (typeid(os) != typeid(ostream))
			os << ad.A_getcity() << " " << ad.A_getStreet() << " " << ad.A_getNumber() << endl;
		else
		os << "city: " << ad.A_getcity() << "street: " << ad.A_getStreet() << "houseNumber " << ad.A_getNumber() << endl;
		return os;
	}
private:
	string A_city;
	string A_street;
	int A_houseNUmber;
};

	

#endif 

