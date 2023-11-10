#include <iostream>
#include "Class.h"
using namespace std;

int main()
{
	cout << "Œp³‚Ì•×‹­" << endl;

	ClassChild0 testClass{ 100 };
	ClassChild0::ClassChild1 testClass2;
	//Œp³æ‚ªŽ‚Á‚Ä‚¢‚È‚­‚Ä‚à
	//Šî’êƒNƒ‰ƒX‚ªŽ‚ÂŠÖ”‚ðŒÄ‚Ño‚·‚±‚Æ‚ª‚Å‚«‚é
	testClass.Func0();
	testClass.Func1();
	testClass.Func2();

	testClass2.Func0();
	testClass2.Func1();
	testClass2.Func2();

#if false
	//ClassBase testClass( -1 );
	ClassBase testClass{ 0 };

	cout << "********" << endl;


	ClassBase* pTestClass = new ClassBase{ 1 };
	delete pTestClass;
#endif

	return 0;
}