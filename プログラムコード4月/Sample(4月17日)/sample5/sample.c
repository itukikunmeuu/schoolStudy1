#include<stdio.h>

int main(void)
{
	int enemyHp = 100; //敵のHP
	int playerMp = 500; //プレイヤーのMP

	//連続攻撃魔法で敵を倒すまで攻撃する
	while (enemyHp > 0)
	{
		enemyHp -= 10;
		playerMp -= 10;
		printf("敵の残りHP: %d\n", enemyHp);
		printf("プレイヤーの残りMP: %d\n", playerMp);

		//MPがなくなったら強制終了
		if (playerMp <= 0) {
			printf("MP切れ！攻撃終了\n");
			break;
		}
		//敵に回避された
		if (0) {
			printf("よけられたので中断\n");
			break;
		}
		//ほかの敵の攻撃を受けた
		if (0) {
			printf("ほかの敵の攻撃を受けたので中断\n");
			break;
		}
		printf("プレイヤーの残りMP: %d\n", playerMp);
	}
	return 0;
}
/*
	//do-while文の説明
	//①処理を行う
	//②条件を満たしていたら①に戻る
	do {
		printf("do-while文は必ず一度は実行します\n");
	} while (2 < 1);

	//while文の説明
	//①while文に入ったら条件チェックが行われる
	//②条件を満たしていたら処理を行う　満たしていないなら終了
	//①に戻る
	while (2 < 1)
	{
		printf("while文は？\n");
	}
	*/

/*
	int num = 3;

	//true(真)　　0以外
	//false(偽)　0

	while (num+1) {
		printf("あと%d回繰り返します", num);
		num--;
	}

	if (num) {
		//num=0の場合はここの処理は行われない
		//num!=0の場合はここの処理は行われる
	}*/

/*
//for文ちょっと細く
int main(void)
{
	int startCount = 4;
	int loopNum = 4;
	//初期化や継続条件にも変数は使える
	for (int i = 1; i <= loopNum; i++) {
		printf("繰り返し%d\n", i);
	}
	return 0;

}*/

/*
	int hp = 50;

		//HPが0以下になるまで攻撃されつづける
		while (hp > 0)
		{
			hp -= 6;
			printf("残りHP:%d\n", hp);
		}

		//for文に書き換え
		for (hp = 50; hp > 0; hp - -6)
		{
			printf("残りHP:%d\n", hp);
		}

		//①while文に入ったら条件チェックが行われる
		//②条件を満たしていら他処理を行う　満たしていないなら終了
		//①に戻る*/

/*
	printf("for文による繰り返しの練習です\n");

	for (;;) {
		printf("延々と繰り返します\n");
	}
/*
	printf("for文による繰り返しの練習です\n");

	int i;

	for (i = 1; i <= 5; i++)
	{
		printf("%d回目の繰り返しです\n", i);
	}
	printf("カウンタ変数の値は%dです\n",i);

	return 0;
	*/

/*
//繰り返し処理
int main(void) 
{
	int hp0 = 100; //勇者
//	int hp1 = 120; //戦士
//	int hp2 = 80; //僧侶
//	int hp3 = 70; //魔法使い

	int count = 0; //繰り返し回数を数える
	for (count = 1; count <= 4; count++)
	{
		hp0 -= 8;
		printf("%d体目の敵の攻撃！\n", count);
		printf("残りHP:%d\n", hp0);
	}

	printf("count = %d\n",count)
	/*
	//①が実行される
	count = 1;
	//②繰り返す条件チェック
	count <= 4  //trueの場合繰り返す処理（④）を実行する
		//falseの場合はfor文終わり
　　//繰り返し条件を満たした場合は処理が行われる
　　hp0 -= 8; //攻撃を受けた　HPを減らす
	printf("%d体目の敵の攻撃！\n", count);
	printf("残りHP:%d\n", hp0);

	//③命令を実行した後の処理が実行される
	count++;  //count = 2

	//②の条件チェックに戻る

	*/

/*
	for (
		count = 1;//①for文に来た時に最初に実行される
		count <= 4;//②繰り返す条件
		);

	for (
		count = 1; //for文に来た時に最初に実行される
		count <= 4; //繰り返す条件
		count++   //繰り返し命令を実行した後に行われる処理
		)
	{
		//この中身を繰り返す
	}
	return 0;

}*/

/*
	//敵が4体
	hp0 -= 10; //1体目の敵から攻撃を受けた　　HPを10減らす
	printf("残りHP: %d\n", hp0);
	hp0 -= 10; //2体目の敵から攻撃を受けた　　HPを10減らす
	printf("残りHP: %d\n", hp0);
	hp0 -= 10; //3体目の敵から攻撃を受けた　　HPを10減らす
	printf("残りHP: %d\n", hp0);
	hp0 -= 10; //4体目の敵から攻撃を受けた　　HPを10減らす
	printf("残りHP: %d\n", hp0);
	*/

/*
int main(void)
{
	int num = 1;

	int num2 = 0;

	if (num == 0 && num2 == 0) {
		//どっちも0

		if (num == 0) {
			printf("インデントに気を付ける\n");
		}
		else if (num == 0) {

		}
		else {

		}
	}
	
	switch (num)
	{
	case 0:
	    printf("numは0です\n");
        break;
	case 1:
	    printf("numは0です\n");
	    break;
	default:
		printf("numは0です\n");
		break;

	}

	printf("\n");

	if (num == 0 && num2 == 0) { //num.num2ともに0　　and演算
		printf("numは0です\n");
	}
	if (num == 0 || num2 == 0) { //num.num2のどちらかが0　or演算
		printf("numは0もしくはnum2==0です\n");
	}
	else if (num == 1) {
		printf("numは1です\n");
	}
	else if (num == 2) {
		printf("numは2ではありません\n");
	}
	else if (num == 3) {
		printf("numは3ではありません\n");
	}
	else {
		printf("numは0でも1でもありません\n");
	}
	return 0;
}*/