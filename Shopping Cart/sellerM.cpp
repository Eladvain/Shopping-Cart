#include"seller.h"
seller::seller(const char *userName, const char *password, const adress &a) :user(userName, password, a)
{
	SE_arrayOfProduct.reserve(10);
	SE_arrayOfPurchaseConsumers.reserve(10);
}
//_________________________________________________________________________________________________
seller::~seller()
{
	for (int i = 0; i < SE_arrayOfProduct.size(); i++)
		delete SE_arrayOfProduct[i];
}
//__________________________________________________________________________________________________


//_____________________________________________________________________________________________________
void seller::SE_addProduct( product* newProdcut)
{
	if (SE_arrayOfProduct.capacity() == SE_arrayOfProduct.size())
		SE_arrayOfProduct.reserve(SE_arrayOfProduct.capacity() * 2);
	SE_arrayOfProduct.push_back ( newProdcut);
}
//________________________________________________________________________________________________
void seller::SE_addConsumer(user* newConsumer)
{
	if (SE_arrayOfPurchaseConsumers.capacity() == SE_arrayOfPurchaseConsumers.size())
		SE_arrayOfPurchaseConsumers.reserve(SE_arrayOfPurchaseConsumers.capacity() * 2);
	SE_arrayOfPurchaseConsumers.push_back( newConsumer);
}
//__________________________________________________________________________________________
void seller::SE_print()                                const// print his user name
{
	cout << U_UserName << endl;
}
//______________________________________________________________________________________________
void seller::SE_Addfeedback(const feedback& feed)
{
	SE_ArrayOfFeedbacks += feed;
}
//_____________________________________________________________________________________________
bool seller::SE_consumerIsInTheArray(const feedback& feed)
{
	for (int i = 0; i < SE_arrayOfPurchaseConsumers.size(); i++)
	{
		if (SE_arrayOfPurchaseConsumers[i] == feed.C_getConsumer())
			return true;
	}
	return false;
}


//____________________________________________________________________________________________________
const int & seller::SE_getLogicProduct()						const
{
	return SE_arrayOfProduct.size();
}
//________________________________________________________________________________________________
  vector<product *>& seller::SE_getArrayOfProduct()						
{
	return  SE_arrayOfProduct;
}
 //______________________________________________________________________________________

 //____________________________________________________________________________________________________
 bool seller::SE_isconsumerInTheArray(user* cons)
 {
	 for (int i = 0; i < SE_arrayOfPurchaseConsumers.size(); i++)
	 {
		 if (SE_arrayOfPurchaseConsumers[i] == cons)
			 return true;
	}
		 return false;
 }
 //______________________________________________________________________________
 bool seller::AS_findIfConsumerPurchase(user * ptr)
 {
	 for (int i = 0; i < SE_arrayOfPurchaseConsumers.size(); i++)
	 {
		 if (SE_arrayOfPurchaseConsumers[i] == ptr)//we compares the adresses between them
			 return true;
	 }
	 return false;
 }
 //___________________________________________________________________________________
 const int& seller::SE_getLogicfeedback()																const
 {
	 return SE_ArrayOfFeedbacks.logic;
 }
 //______________________________________________________________________________________
 void seller::SE_printAllProduct()																		const
 {
	 vector<product*>::const_iterator itB = SE_arrayOfProduct.begin();
	 vector<product*>::const_iterator itE = SE_arrayOfProduct.end();
	 for (; itB < itE; ++itB)
		 cout << *itB << endl;
 }
 void seller::print()																					const
 {
	 user::print();
 }
 void seller::setSizeOfVector(int size)
 {
	 SE_arrayOfProduct.resize(size);
 }
 void seller::swapV(int& index1)
 {
	 SE_arrayOfProduct[index1] = SE_arrayOfProduct[index1+1];
 }