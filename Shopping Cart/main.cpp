#include"product.h"
#include"consumer.h"
#include"seller.h"
#include"feedback.h"
#include"appSystem.h"
int main()
{
	ifstream in("usersList.txt", ios::_Nocreate);
	appSystem a(in);
	a.AS_display();
	in.close();
	ofstream out("usersList.txt", ios::trunc);
	a.save(out);
	out.close();

	system("pause");
}