#include <iostream>
#include "Class.h"
using namespace std;

int main()
{
	cout << "�p���̕׋�" << endl;

	ClassChild0 testClass{ 100 };
	ClassChild0::ClassChild1 testClass2;
	//�p���悪�����Ă��Ȃ��Ă�
	//���N���X�����֐����Ăяo�����Ƃ��ł���
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