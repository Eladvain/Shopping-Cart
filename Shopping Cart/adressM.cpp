#include"product.h"
//bool adress::A_checkValidity(const char*city, const char*street, const int&  houseNumber)// w
bool adress::A_checkValidity(const string& city, const string&street, const int&  houseNumber)// we will make pointer to adress if the validation test will be true we will dynamicly allocated memory for it 
{
	//if (strlen(city) > (MAX_LENGTH_CITY_STREET) || strlen(street) > MAX_LENGTH_CITY_STREET)
		//return false;
	return true;
}
//__________________________________________________________________________________________________________________

//__________________________________________________________________________________________________________________
void adress::A_setCity(const string& city)
{
	A_city = city;
}
//__________________________________________________________________________________________________________________
void adress::A_setStreet(const string &street)
{
	A_street=street;
}
//__________________________________________________________________________________________________________________
void adress::A_setHouseNumber(const int& num)
{
	A_houseNUmber = num;
}

//__________________________________________________________________________________________________________________

adress::adress(const string&city, const string&street, const int&  housenumber)
{
	A_city = city;
	A_street = street;
	A_houseNUmber = housenumber;
	
}
//___________________________________________________________________________________________________________________
void adress::A_adressPrint()						const
{
	cout << A_city << "     " << A_street << "    " << A_houseNUmber << endl;
}
//_______________________________________________________________________________________________________________
adress::adress(const adress& other)//copy constructor
{
	A_city= other.A_city;
	A_street= other.A_street;
	A_houseNUmber = other.A_houseNUmber;
}
//______________________________________________________________________________________________________________
string  adress::A_getcity()						const
{
	return A_city;
}
//______________________________________________________________________________________________________________
string  adress::A_getStreet()					const
{
	return A_street;
}
//______________________________________________________________________________________________________________
const int& adress::A_getNumber()					const
{
	return A_houseNUmber;
}
//______________________________________________________________________________________________________________
