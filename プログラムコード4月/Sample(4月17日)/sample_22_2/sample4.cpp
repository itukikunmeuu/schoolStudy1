#include<iostream>
#include<cmath> //���w�֐�

//include<stdio.h>
//include<stdlib.h>
//��C++�ŏ�Ɋ܂܂��֐����g�������I
//#include<cstdio>
//#include<cstdlib>

//<cmath>
//���@���ŏ�Ɋ܂܂��֐����g�������I
//<math.h>

using namespace std;

int main()
{
	//���p�O�p�`�̎Εӂ̒��������߂�v���O����
	double a, b;  //��ӂƍ���

	cout << "���p������2�ӂ̒�������͂��Ă��������@>" << flush;
	cin >> a >> b;

	//�Εӂ̒������v�Z����
	double result = (a * a + b * b); //sqrt(x) �ł��̕����������߂�
	cout << "�Εӂ̒�����" << result << "�ł��B" << endl;

	//abs(x)  �@:x
	//floor(x)�@:
	//cell(x)   :
	//fmod(x,y) :x
	//sqrt(x)   :x
	//...���@   :


	return 0;
}