#include<iostream>
using namespace std;

//��������a�ɕϊ�����֐�
//���a�ł͂Ȃ��N���w�肳�ꂽ�ꍇ0�ɂ���
void WestenToSyouwa(int& x)
{
	if (x >= 1926 && x <= 1989) //1926�N�`1989�����a
	{
		x -= 1925;
	}
	else
	{
		x = 0;
	}
}


void Syouwa()
{
	int year;

	cout << "�������͂��Ă������� > " << flush;
	cin >> year;  //�L�[�{�[�h���琔�l����͂���

//	cout << "����" << year << endl;
	WestenToSyouwa(year);
	if (year != 0)
	{
		cout << "���̔N�͏��a" << year <<"�N�ł�" << endl;
	}
	else
	{
		cout << "���̔N�͏��a�ł͂���܂���B" << endl;
	}

		
}

int main()
{
	Syouwa();
	Syouwa();

	return 0;
}
