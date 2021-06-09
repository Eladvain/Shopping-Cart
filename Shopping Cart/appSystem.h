#ifndef _AS_H
#define _AS_H
#include<vector>
#include<fstream>
#include"consumerAndSeller.h"
//#include"ArrayTemplate.h"
class appSystem 
{
public:
	static const int MAXSIZEINPUT = 80;
	appSystem();
	appSystem(ifstream& in);
	~appSystem();
	
	void AS_addUser(user *ptr);
	user *AS_createNewUser(int i);
	void AS_display();
	void AS_displayForConsumer();
	user* returnExistUser(const char*name, const char*password)const;
	void AS_displayForSeller();
	void AS_cosumerMenu(consumer *cons);
	void AS_consumerAndSellerMenue();
	void AS_printAllProduct()											const;
	bool AS_printProductSpecificName(char *name)						const;
	void AS_printShoppingCart()											const;
 	product*   AS_getProductBySerialNumber(int serial)					const;
	bool AS_printAllSellerUserName()									const;
	user* AS_findSellerForFeedback(char *name)							const;
	void AS_printAllConsumer()				const;
	feedback AS_getFeedback(consumer *cons);
	bool AS_existUser(char*name)										const;
	void AS_menuForSeller(seller *currSeller);
	void AS_OrderMenuForConsumer(consumer *consumer);
	bool AS_checlValidityOfDate(char *date);
	void operatorCheck();
	consumer* returnConsumerByUserName(const char*name)					const;
	void deleteFromShoppingCurt(product* arrayOfProducts,int &size);
	const user* operator+=(user*newuser);
	void AS_printConsumerAndSellerUsers()								const;
	void save(ofstream & out);
private:
	vector<user*> AS_arrayOfUsers;

};
#endif // !_AS_H
