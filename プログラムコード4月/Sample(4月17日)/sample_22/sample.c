#include<stdio.h>

#define TEST_NUM 5

//列挙体の復習
//一連のデータ（曜日など）をまとめて定数として定義するのに使用する
// 今回の例　RPGのアイテム
// いろいろな種類があるが
//回復、ダメージ、状態異常の回復、イベント等のカテゴリに分かれる

typedef enum ItemType
{
	ITEM_TYPE_HEIL,		//回復アイテム			0
	ITEM_TYPE_DAMAGE,	//ダメージアイテム		1
	ITEM_TYPE_POWER,	//ステータスアップアイテムを追加 2
	ITEM_TYPE_RECOVER,	//状態異常の回復		3
	ITEM_TYPE_EVENT,	//イベントアイテム		4
	ITEM_TUPE_OTHER,    //特殊アイテム　アイテムごとの専用処理が必要　5

	ITEM_TYPE_NUM,      //アイテムのタイプ数　6
						//アイテムの第五に定義しておけば
						//アイテムタイプの種類が増えてもそれに合わせえてこの中の値も変化する
	/*  //関数に数字を入れると増えていく数字が変動していく（以下参照）
	ITEM_TYPE_HEIL,		//0
	ITEM_TYPE_DAMAGE = 3,	//3
	ITEM_TYPE_POWER,	//4
	ITEM_TYPE_RECOVER,	//5
	ITEM_TYPE_EVENT,	//6
	*/
}ItemType;


int main(void)
{
	//処理がソースの何行目にかかれているかを確認できる
	printf("ソースコードのファイル名%s\n",__FILE__ );
	printf("このprintfは%d行目に書かれている\n", __LINE__);
	//コンパイルを行った日時を確認できる
	printf("コンパイルを行った日:%s\n", __DATE__);
	printf("コンパイルを行った時間:%s\n",__TIME__);
	


	//int型　整数
	//float型　小数
	//char型　半角一文字

	//ItemType型;enumで定義された値のうち、いずれかが入る
	ItemType type;
	type = ITEM_TYPE_HEIL;
	type = ITEM_TYPE_EVENT;
//	type = 16;  //ItemType 実はintなので入れることはできるがよくない

	printf("enumが実は数字であることを確認\n");
	printf("ITEM_TYPE_RECIVER = %d\n", ITEM_TYPE_RECOVER);

	for (int i = 0; i < ITEM_TYPE_NUM; i++)
	{

	//アイテムを使った時の処理を書きたい
	switch (type)
	{
//	case 0: //数字だとわかりずらい
	case ITEM_TYPE_HEIL:
		printf("HPを10回復\n");
		break;
	case ITEM_TYPE_DAMAGE:
		printf("敵に10回復\n");
		break;
	case ITEM_TYPE_POWER:
		printf("最大HPが3上がった\n");
		break;
	case ITEM_TYPE_RECOVER: //修正に対応しずらい
		printf("毒を回復\n");
		break;
	case ITEM_TYPE_EVENT:
		printf("使っても何も起こらない\n");
		break;
	case ITEM_TUPE_OTHER:
		printf("アイテムによっておこる効果が変わる\n");
		break;
	}

	}

	return 0;
}