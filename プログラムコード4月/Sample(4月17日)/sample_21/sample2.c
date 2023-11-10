#include<stdio.h>

//列挙体
//定数をまとめて定義するのに便利
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
		SUN,	 //内部的には0
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

	ITEM_KIND			//5 列挙体の要素の数
}Item;

int main(void)
{
	printf("ここは%d行目です\n", __LINE__);
	printf("コンパイル日は%sです\n", __DATE__);
	printf("コンパイル時間は%sです\n", __TIME__);
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

	printf("すべてのアイテムの値段を表示しますか");
	for (int i = 0; i < ITEM_KIND; i++)
	{
		printf("%d円\n", price[i]);
	}
	*/

	/*
	//int型 :整数
	//float型　:小数
	//char型　:文字

	//列挙体Week ; Weekで定義した定数が入る
	Week wk = SUN;
	wk = MON;

	switch (wk)
	{
	case SUN:
		printf("日曜日なので休みです\n");
		break;
	case MON:
		printf("月曜日なので仕事です\n");
		break;
	case TUE:
		printf("火曜日なので仕事です\n");
		break;
	case WED:
		printf("水曜日なので午前のみ仕事です\n");
		break;
	case THU:
		printf("木曜日なので仕事です\n");
		break;
	case FRI:
		printf("金曜日なので仕事です\n");
		break;
	case SAT:
		printf("土曜日なので午前のみ仕事です\n");
		break;
	}
	*/
	return 0;
}