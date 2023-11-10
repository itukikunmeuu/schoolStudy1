#include<stdio.h>

//�萔
#define BUFF_NONE 0		//�o�t�Ȃ�
#define BUFF_ATTCK 1	//�U���̓A�b�v
#define BUFF_SPEED 2	//�ړ��̓A�b�v
#define BUFF_DEF 3		//�h��̓A�b�v

//�v���C���[�ւ̃o�t�̎��
typedef enum Buff
{
	NONE,		//�Ȃ�
	ATTACK,		//�U����
	SPEED,		//�ړ����x
	DEF,		//�h���
}Buff;

//�X�e�[�^�X�A�b�v���������p��
typedef union BuffEffect
{
	int attack;		//�U���̓A�b�v��
	float speed;	//�ړ����x�㏸��
	int def;		//�h��̓A�b�v��
	//...			//�o�t�̎�ނ��������烁���o��������
}BuffEffect;

//�v���C���[�\����
typedef struct Player
{
	int hp;

	//�o�t���ʁi�X�e�[�^�X�A�b�v�j
	//�������̃X�e�[�^�X�A�b�v�����邪�A�i�U���́A�f������...�j
	//��̂ݗL���i�U���͂̃X�e�[�^�X�����Ă���Ƃ��ɑf���������ƍU���͂͏�����j
	//�V�����o�t�����ƌÂ��̂͏�����
	Buff buffType;			//���݂̃o�t�̎��
	BuffEffect buffEffect;  //�X�e�[�^�X�A�b�v���


}Player;

int main(void)
{
	//�f�[�^�^
	//int�^�@����������
	//float�^�@����������
	//char�^�@�������ꕶ�������

	//�񋓑̂ł���Buff�^;�񋓑̂Œ�`�����萔
	Buff bf;
	bf = NONE;
	bf = ATTACK;
	bf = SPEED;
	bf = DEF;
	bf = 10;  //�r���h�͒ʂ邪�悭�Ȃ�


	Player player;
	//������
	player.hp = 100;			
	player.buffType = BUFF_NONE;			

	//�U���̓o�t
	player.buffType = ATTACK;			//�U����UP�ɐݒ�
	player.buffEffect.attack = BUFF_ATTCK;		//�U���͂̏㏸�ʂ�ݒ�


	//�ړ����x�o�t
	player.buffType = SPEED;			//�ړ����xUP�ɐݒ�
	player.buffEffect.speed = BUFF_SPEED;    //�ړ����x�̏㏸�ʂ�ݒ�

	switch(player.buffType)
	{
	case NONE:
		break;
	case ATTACK:
		prinrf("�U���͂�%d�オ�����Ă���\n", player.buffEffect.attack);
		break;
	case SPEED:
		prinrf("�ړ����x��%d�オ�����Ă���\n", player.buffEffect.speed);
		break;
	case DEF:
		prinrf("�h��͂�%d�オ�����Ă���\n", player.buffEffect.def);
		break;
	}


	return 0;
}