#ifndef _SC_H
#define _SC_H
#include "consumer.h"
#include<vector>
#include"order.h"
#include<string>
class shoppingCart
{
public:
	friend class appSystem;
	~shoppingCart();
	shoppingCart(const  string& name,consumer* cons);
	//we are not releaseing the products or the productArray in that class becouse the order class will take care of it
	void S_setUserName(const string& name);
	void S_setProductArray();
	void S_setPrice();
	const string& S_getName()							const;
	const float& S_getPrice()						const;
	vector< product*> S_getProductArray()			const;
	void S_addproduct(product* newProduct);
	void S_shoppingCartPrint()						const;
	product* S_getproductByserialNumber(int serial)	;
	void removeProductFromCart(vector<product *> product, int size);
	
private:
	shoppingCart(const shoppingCart &other) = delete; // we dont want to have the possibility to copy shopping cart, and we hold shopping cart at consumer as pointer
	vector<product*> S_ProductArray;
	float S_price;
	string S_consUserName;
	order *S_order;
	consumer*S_consumer ;

};
#endif // !_SC_H

