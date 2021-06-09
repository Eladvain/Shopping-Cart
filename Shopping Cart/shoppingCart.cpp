#include"shoppingCart.h"
shoppingCart::shoppingCart(const string& name,consumer *cons)
{
	S_ProductArray.reserve(2);
	S_setUserName(name);
	S_setPrice();
	S_consumer = cons;
	S_order=new order(this);
}
//________________________________________________________________
shoppingCart::~shoppingCart()
{
	delete S_order;
	// we dont want to delete the product belong to that array becouse they are belong to a seller, when the seller will die they will delete
	S_consumer = nullptr;// in order to avoid an enfinity loop
}
//_________________________________________________________________
void shoppingCart::S_setUserName(const string &  name)
{
	S_consUserName= name;
}
//_________________________________________________________________
//_________________________________________________________________
void shoppingCart::S_setPrice()
{
	S_price = 0;
}
//_________________________________________________________________
const string& shoppingCart::S_getName()							const
{
	return S_consUserName;
}
//_________________________________________________________________
const float& shoppingCart::S_getPrice()							const
{
	return S_price;
}
//_________________________________________________________________
vector< product*> shoppingCart::S_getProductArray()					const
{
	return S_ProductArray;
}
//_________________________________________________________________
void shoppingCart::S_addproduct(product* newProduct)
{
	if (S_ProductArray.size() == S_ProductArray.capacity())
		S_ProductArray.reserve(S_ProductArray.capacity() * 2);
	S_price += newProduct->P_getprice();
	
	S_ProductArray.push_back( newProduct);
}
//_______________________________________________________________________________________________________
void shoppingCart::S_shoppingCartPrint()					const
{
	vector<product*>::const_iterator itB = S_ProductArray.begin();
	vector<product*>::const_iterator itE = S_ProductArray.end();
	for (; itB < itE; ++itB)
	{
		cout <<*itB<<endl;

	}
}
//_____________________________________________________________________________________________________
product* shoppingCart::S_getproductByserialNumber(int serial)		
{
	int i = 0;
	while (i < S_ProductArray.size())
	{
		if (S_ProductArray[i]->P_getSerialNumber() == serial)
			return S_ProductArray[i];
		i++;
	}
	return nullptr;
}
void shoppingCart::removeProductFromCart(vector<product *> product, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < S_ProductArray.size(); j++)
		{
			if (S_ProductArray[j] == product[i])
			{
				for (int k = j; k <S_ProductArray.size()-1; k++)
				{
					S_ProductArray[k] = S_ProductArray[k + 1];
				}
				S_ProductArray.resize(S_ProductArray.size() - 1);
			}
		}
	}
}