#include<stdio.h>

#define TEST_NUM 5

//�񋓑̂̕��K
//��A�̃f�[�^�i�j���Ȃǁj���܂Ƃ߂Ē萔�Ƃ��Ē�`����̂Ɏg�p����
// ����̗�@RPG�̃A�C�e��
// ���낢��Ȏ�ނ����邪
//�񕜁A�_���[�W�A��Ԉُ�̉񕜁A�C�x���g���̃J�e�S���ɕ������

typedef enum ItemType
{
	ITEM_TYPE_HEIL,		//�񕜃A�C�e��			0
	ITEM_TYPE_DAMAGE,	//�_���[�W�A�C�e��		1
	ITEM_TYPE_POWER,	//�X�e�[�^�X�A�b�v�A�C�e����ǉ� 2
	ITEM_TYPE_RECOVER,	//��Ԉُ�̉�		3
	ITEM_TYPE_EVENT,	//�C�x���g�A�C�e��		4
	ITEM_TUPE_OTHER,    //����A�C�e���@�A�C�e�����Ƃ̐�p�������K�v�@5

	ITEM_TYPE_NUM,      //�A�C�e���̃^�C�v���@6
						//�A�C�e���̑�܂ɒ�`���Ă�����
						//�A�C�e���^�C�v�̎�ނ������Ă�����ɍ��킹���Ă��̒��̒l���ω�����
	/*  //�֐��ɐ���������Ƒ����Ă����������ϓ����Ă����i�ȉ��Q�Ɓj
	ITEM_TYPE_HEIL,		//0
	ITEM_TYPE_DAMAGE = 3,	//3
	ITEM_TYPE_POWER,	//4
	ITEM_TYPE_RECOVER,	//5
	ITEM_TYPE_EVENT,	//6
	*/
}ItemType;


int main(void)
{
	//�������\�[�X�̉��s�ڂɂ�����Ă��邩���m�F�ł���
	printf("�\�[�X�R�[�h�̃t�@�C����%s\n",__FILE__ );
	printf("����printf��%d�s�ڂɏ�����Ă���\n", __LINE__);
	//�R���p�C�����s�����������m�F�ł���
	printf("�R���p�C�����s������:%s\n", __DATE__);
	printf("�R���p�C�����s��������:%s\n",__TIME__);
	


	//int�^�@����
	//float�^�@����
	//char�^�@���p�ꕶ��

	//ItemType�^;enum�Œ�`���ꂽ�l�̂����A�����ꂩ������
	ItemType type;
	type = ITEM_TYPE_HEIL;
	type = ITEM_TYPE_EVENT;
//	type = 16;  //ItemType ����int�Ȃ̂œ���邱�Ƃ͂ł��邪�悭�Ȃ�

	printf("enum�����͐����ł��邱�Ƃ��m�F\n");
	printf("ITEM_TYPE_RECIVER = %d\n", ITEM_TYPE_RECOVER);

	for (int i = 0; i < ITEM_TYPE_NUM; i++)
	{

	//�A�C�e�����g�������̏�������������
	switch (type)
	{
//	case 0: //�������Ƃ킩�肸�炢
	case ITEM_TYPE_HEIL:
		printf("HP��10��\n");
		break;
	case ITEM_TYPE_DAMAGE:
		printf("�G��10��\n");
		break;
	case ITEM_TYPE_POWER:
		printf("�ő�HP��3�オ����\n");
		break;
	case ITEM_TYPE_RECOVER: //�C���ɑΉ������炢
		printf("�ł���\n");
		break;
	case ITEM_TYPE_EVENT:
		printf("�g���Ă������N����Ȃ�\n");
		break;
	case ITEM_TUPE_OTHER:
		printf("�A�C�e���ɂ���Ă�������ʂ��ς��\n");
		break;
	}

	}

	return 0;
}