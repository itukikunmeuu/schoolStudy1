#include<stdio.h>

//�񋓑�
//�萔���܂Ƃ߂Ē�`����̂ɕ֗�
/*
#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define TRI 5
#define SAT 6
*/
typedef enum Week
{
		SUN,	 //�����I�ɂ�0
		MON,	 //1
		TUE,	 //2
		WED,	 //3
		THU,	 //4
		FRI,	 //5
		SAT,	 //6

}Week;

typedef enum Item
{
	ITEM_YAKUSO,		//0
	ITEM_DOKUKESI,		//1
	ITEM_KAGI,			//2
	ITEM_KAGAMI,		//3
	ITEM_MANGEKYOU,		//4

	ITEM_KIND			//5 �񋓑̗̂v�f�̐�
}Item;

int main(void)
{
	printf("������%d�s�ڂł�\n", __LINE__);
	printf("�R���p�C������%s�ł�\n", __DATE__);
	printf("�R���p�C�����Ԃ�%s�ł�\n", __TIME__);
	/*
	Item item;
	item = ITEM_YAKUSO;

	int price[ITEM_KIND] =
	{
		16,		//ITEM_YAKUSO
		20,		//ITEM_DOKUKESI
		100,	//ITEM_KAGI
		1000,	//ITEM_KAGAMI
		40		//ITEM_MANGEKYOU
	};

	printf("���ׂẴA�C�e���̒l�i��\�����܂���");
	for (int i = 0; i < ITEM_KIND; i++)
	{
		printf("%d�~\n", price[i]);
	}
	*/

	/*
	//int�^ :����
	//float�^�@:����
	//char�^�@:����

	//�񋓑�Week ; Week�Œ�`�����萔������
	Week wk = SUN;
	wk = MON;

	switch (wk)
	{
	case SUN:
		printf("���j���Ȃ̂ŋx�݂ł�\n");
		break;
	case MON:
		printf("���j���Ȃ̂Ŏd���ł�\n");
		break;
	case TUE:
		printf("�Ηj���Ȃ̂Ŏd���ł�\n");
		break;
	case WED:
		printf("���j���Ȃ̂ŌߑO�̂ݎd���ł�\n");
		break;
	case THU:
		printf("�ؗj���Ȃ̂Ŏd���ł�\n");
		break;
	case FRI:
		printf("���j���Ȃ̂Ŏd���ł�\n");
		break;
	case SAT:
		printf("�y�j���Ȃ̂ŌߑO�̂ݎd���ł�\n");
		break;
	}
	*/
	return 0;
}