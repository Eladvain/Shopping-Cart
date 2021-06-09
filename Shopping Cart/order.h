#ifndef _OR_H
#define _OR_H
#include"product.h"
#include<vector>
class consumer;
class shoppingCart;
class order 
{
public:
	order(shoppingCart  *ChossenshoppingCart);
	~order();
	 void O_print()														const;
	void O_addItems(product* itemToPurchase);
	void O_deleteProductFromSeller(consumer *cons );
	const float& O_getPrice()											const;                      
	bool O_checkifProductAlreadyChoose(const int serial)				const;
	vector<product*> O_getArrayOfProduct()								;
private:
	order(const  order & other) = delete;// we dont want to have the opption to copy an order
	vector<product*> O_arrayOfChossenProduct;
	float O_finalPrice;
	shoppingCart* O_shoppingCart;

	

};
#endif 
