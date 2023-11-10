#include<stdio.h>

//�\���̂̒�`
//�f�[�^���ЂƂ܂Ƃ߂ɂ�������
//�V�����f�[�^���܂Ƃ߂�
//int�^�Afloat�^�Achar�^�A ...Unit�^

typedef struct Unit
{
	int level;
	int hp;
	int mp;
	int atk;
	int def;
}Unit;

void dispStatus(Unit unit)
{
	printf("���x��:%d\n",unit.level);
	printf("HP:%d\n",unit.hp);
	printf("MP:%d\n",unit.mp);
	printf("�U��:%d\n",unit.atk);
	printf("�h��:%d\n",unit.def);
}

//���j�b�g�̃��x�����グ��
//�֐��̓����œn���ꂽ�����̂̒��g��ύX������
void levelUp(Unit* pUnit)
{
	//�\���̂̃|�C���^����
	//���̃����o�ɃA�N�Z�X������
	//�A���[���Z�q���g�p����
	if (pUnit->level >= 99) return; //���x�����ő�l�̏ꍇ�͉��������ɏI��

	pUnit->level++;
	pUnit->hp += 5;
	pUnit->mp += 5;
	pUnit->atk += 5;
	pUnit->def += 5;
}

int main(void)
{
	//�\���̂ɔz��
	Unit unitTbl[3];

	//�����X�e�[�^�X�̐ݒ�
	for (int i = 0; i < 3; i++)
	{
		unitTbl[i].level = 1+i;
		unitTbl[i].hp = 50;
		unitTbl[i].mp = 10;
		unitTbl[i].atk = 15;
		unitTbl[i].def = 10;
	}

	//�X�e�[�^�X�̕\��
	for (int i = 0; i < 3; i++)
	{
		dispStatus(unitTbl[i]);
	}

	/*
	Unit unit = { 1,50,20,20,10 }; //�������@�����o�̏ォ�珇�ɑ�������

		dispStatus(unit);
		levelUp(&unit);
		dispStatus(unit);

	printf("���x��:%d\n", unit.level);

	*/

	return 0;
}