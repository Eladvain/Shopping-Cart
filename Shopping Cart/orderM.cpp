#include"order.h"
#include"shoppingCart.h"
#include"seller.h"
order::order(shoppingCart  *ChossenshoppingCart)
{
	
	O_shoppingCart = ChossenshoppingCart;
	O_arrayOfChossenProduct.reserve(2);
}
//______________________________________________________________________
order::~order()
{
// we dont want to delete the products which the array contain
}
//_______________________________________________________________________________
void order::O_print()					const
{
	vector<product*>::const_iterator itB = O_arrayOfChossenProduct.begin();
	vector<product*>::const_iterator itE = O_arrayOfChossenProduct.end();
	for(;itB<itE;++itB)
	{
		cout << *itB << endl;
	}
}

//_______________________________________________________________________________
void order::O_addItems(product* itemToPurchase) 
{
	if (O_arrayOfChossenProduct.size() == O_arrayOfChossenProduct.capacity())
		O_arrayOfChossenProduct.reserve(O_arrayOfChossenProduct.capacity() * 2);
	O_finalPrice += itemToPurchase->P_getprice();
	O_arrayOfChossenProduct.push_back(itemToPurchase);
}
//_______________________________________________________________________________
void order::O_deleteProductFromSeller(consumer *cons)// after the purchase we eant to delete the product from the seller array 
{
	for (int i = 0; i < O_arrayOfChossenProduct.size(); i++)
	{
		seller* temp = O_arrayOfChossenProduct[i]->P_getSeller();
		if (temp->SE_isconsumerInTheArray(cons) == false)//if he already bought something from that seller
		{
			temp->SE_addConsumer(cons);
		}
		product* newCurr = O_arrayOfChossenProduct[i];
			newCurr->P_productDeleteFromSelle(newCurr);// delete that product
	}
}
//___________________________________________________________________________________________________
const float& order::O_getPrice()										const									
{
	return O_finalPrice;
}
//_______________________________________________________________________________________________________

//_______________________________________________________________________________________________________
bool order::O_checkifProductAlreadyChoose(const int serial)				const// in case for selecting the same product more than once
{
	for (int i = 0; i < O_arrayOfChossenProduct.size(); i++)
	{
		if (O_arrayOfChossenProduct[i]->P_getSerialNumber() == serial)
			return true;
	}
	return false;
}
vector<product*> order::O_getArrayOfProduct()
{
	return O_arrayOfChossenProduct;
}