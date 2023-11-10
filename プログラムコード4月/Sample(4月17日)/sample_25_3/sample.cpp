#include<iostream>
using namespace std;

int main()
{
	bool isFlag = true;
#if false
	if (isFlag)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE" << endl;
	}
#else
	//3€‰‰ŽZŽq‚ðŽg‚Á‚Ä‘‚«Š·‚¦
	cout << (isFlag ? "TRUE" : "FALSE") << endl;
#endif
	/*
	int num0 = 60;
	int num1 = 60;
	-num0;			//- ’P€‰‰ŽZŽq
	num0 + num1;	//+ 2€‰‰ŽZŽq
	*/
	return 0;
}

