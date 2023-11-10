#pragma once
#include <iostream>
using namespace std;


//				�@���p���Ƃ́H��
//�@����N���X����ɐV�����N���X����邱�Ƃ��ł���
//�@������p���Ƃ���

//�����ClassBase����ɐV�����N���X���쐬����
//��ɂȂ�N���X�̂��Ƃ����N���X�ƌĂ�
class ClassBase
{
public:

	ClassBase() :
		m_num(0)
	{
		cout << "ClassBase�̈����Ȃ��R���X�g���N�^" << m_num << endl;

	}

	ClassBase(int num):
		m_num(num)
	{
		cout << "ClassBase�̃R���X�g���N�^" << m_num << endl;
	}
	~ClassBase()
	{
		cout << "ClassBase�̃f�X�g���N�^" << m_num <<  endl;
	}

	void Func0()
	{
		cout << "ClassBase::Func0" << m_num << endl;
	}
	void Func1()
	{
		cout << "ClassBase::Func1" << m_num << endl;
	}
	void Func2()
	{
		cout << "ClassBase::Func2" << m_num << endl;
	}
	//pribate�ȃ����o�[�̓N���X�O����Q�Ƃł��Ȃ�
	//����͌p����̃N���X�ł����l
	//�p����̃N���X�����N���X�̎��ϐ���ύX�������ꍇ�͂悭����
private:
	//�ʒu����U���͂ȂǁA���N���X�Ɏ������āA
	//�p����ł��ύX���s����ϑ��͂�����ł�����

	//���������ꍇ��protected�Ő錾����
	//protected�ȕϐ��A�֐��̓N���X�O����͌����Ȃ���
	//�p����̃N���X����͌��邱�Ƃ��ł���

	//�悭�킩��Ȃ��������͊��N���X�̃����o�ϐ���
	//���ׂ�protected�ł����Ǝv��
protected:

	void ProtectedFunc();
	{
		cout << "protected�Ȋ֐�" << endl;
	}

	int m_num;
};

//ClassBase�����ƂɐV�����N���X���쐬����
//ClassBase���p�����ĐV�����N���X���쐬����

//�N���X�̐錾���Ɍp�����ƂȂ�N���X���w�肷��K�v������
class ClassChild0 : public ClassBase
{
public:
	ClassChild0()
	{
		//���N���X�̃R���X�g���N�^�𖾎��I�ɌĂ΂Ȃ��ꍇ�B
		//�p����̃N���X�̌��i�ƃ��X�^���Ăяo���O��
		//�����Ȃ��̌p����R���X�g���N�^���Ăяo�����


		cout << "ClassChild0�̃R���X�g���N�^" << endl;
	}
	ClassChild0(int num):
		ClassBase(num) //�p�����N���X�̃R���X�g���N�^�𖾎��I�ɌĂ�
	{
		cout << "ClassChild0�̈����t���R���X�g���N�^" << endl;

	}
	~ClassChild0()
	{
		cout << "ClassChild0�̃f�X�g���N�^" << endl;

		//�p����̃f�X�g���N�^���Ă΂ꂽ��A
		//�p����̃f�X�g���N�^���Ă΂��
	}

	//������ClassBase���p�������N���X
	class ClassChild1 : public ClassBase
	{
	public:
		ClassChild1()
		{
			cout << "ClassChild1�̃R���X�g���N�^" << endl;
		}
		~ClassChild1()
		{
			cout << "ClassChild1�̃f�X�g���N�^" << endl;
		}

		//���N���X��Func0���g���̂ł͂Ȃ��A
		//���̃N���X�̓���ȏ������s������
		void Func0()
		{
			cout << "ClassChild1�̓����Func0" << endl;
			//protected�ȕϐ��A�֐��͌p���悩��Ăяo�����Ƃ��ł���
			m_num = 999;
			ProtectedFunc();
		}
	};

};
