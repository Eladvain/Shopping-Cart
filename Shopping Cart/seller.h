#ifndef _SE_H
#define _SE_H
#include"ArrayTemplate.h"
#include"consumer.h"
#include"ArrayTemplate.h"
#include<vector>
class feedback;
class seller:virtual public user
{
public:
	friend class appSystem;
	virtual ~seller();
	seller(const char *SE_userName,const char *SE_password, const adress &a);
	void SE_setArrays();
	void SE_addProduct( product* newProdcut);
	void SE_addConsumer(user* consumer);
	void SE_print()																					const;
	void  SE_Addfeedback(const feedback& feed);
	bool  SE_consumerIsInTheArray(const feedback& feed);
	 const int & SE_getLogicProduct()																const;
	 vector<product *>& SE_getArrayOfProduct()													;
	 bool SE_isconsumerInTheArray(user* cons);
	 bool AS_findIfConsumerPurchase(user * ptr);
	 const int& SE_getLogicfeedback()																const;
	 void SE_printAllProduct()		const;
	 void setSizeOfVector(int size);
	 void swapV(int& index1);
	 void PrintAllFeedbacks()
	 {
		 for (int i = 0; i < SE_ArrayOfFeedbacks.logic; i++)
		 {
			 
		 }
	 }
	virtual void print()																					const;
private:
	Array<feedback> SE_ArrayOfFeedbacks;
	vector<product*> SE_arrayOfProduct;
	vector<user *> SE_arrayOfPurchaseConsumers;
	
};
#endif // !_SE_H
