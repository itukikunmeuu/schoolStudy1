#include<stdio.h>

//for文の復習
int main(void)
{
	int answer = 0;

	//1から100の間に存在する7の倍数の合計を計算する
	//answer ＝ 7 + 14 + 21 + 28 + 35...
	//2パターンくらい方法を考える

	//for文を工夫する
	for (int i = 1; i <= 100; i++) {
		if (i % 7 == 0) {
			answer += i;
		}
	}

	//7の倍数をはじく

	printf("7の倍数の合計は %dです\n", answer);
	return 0;
}
//無限ループ
   /*
	int hp = 50;

	int damage = 8;

	//プレイヤーの防御力をチェックしてダメージを減らす
	damage -= 100;

	while (hp > 0) 
	{
		hp -= 8;
		printf("残りHP:%d\n", hp);
	}

	//無限ループ
	while (1) {//while(1)で無限ループ

		//条件チェックして無限ループを抜ける
		if (1) {
			break;
		}
	}
	*/
//continue文
	/*
	int answer = 0;

	//1から１０までの足し算して、答えを出力する
	//繰り返し処理は使用すること！（for　while）

	//1～１０までの足し算
//	answer = 0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;
	answer = 0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;

	//足し算を１０回行う処理
	answer = 0;
	for (int i = 0; i < 10; i++) {

		printf("足そうとしている数 %d\n", i+1);

		//3の倍数を足そうとした場合それを行わない
		if (((i + 1) % 3 == 0) ){
			continue;
		}
		//足し算を行う
		answer += i+1;
	printf("answer = %d\n", answer);

	}
	printf("answer = %d\n", answer);
	*/
//while文の足し算1～10　演習
    /*
	int answer = 0;
	answer = 0;
	
	int addNum = 1;
	while (addNum <= 10) {
		answer += addNum;
		addNum++;
	}
	printf("answer= %d\n", answer);
	*/
//for文の足し算１～10　演習
    /*
int answer = 0;

	//1から１０までの足し算して、答えを出力する
	//繰り返し処理は使用すること！（for　while）
	for (int i = 1; i <= 10; i++) {
		printf("ループ回数%d\n", i);
		//足し算を行う
		answer += i;
	}

	printf("answer = %d\n", answer);
	*/
//break文の復習　while
	/*
	//break文の復習
	int inputNum = 8; //プレイヤーが入力した数字
	int count = 1;   //表示する数字
	while (1){
		printf("数字：%d\n", count);
		//プレイヤーが入力した数字が表示されたら終了
		if (count == inputNum) {
			break;
		}
		//100まで表示されたら終了
		if (count >= 100)
		{
			break;
		}
		count++;
	}
	*/
//break文の復習　for
	/*
	//while文だけでなくfor文も強制終了できる
	for (int i = 0; i < 100; i++) {
		int dispNum = count + 1;
		priintf("数字:%d\n", dispNum);

		//プレイヤーが入力した数字が表示されたら終了
		if (dispNum == inputNum) {
			break;
		}
	}
	*/
//do-whileの復習
    /*
	//do-while文の復習
	do {
		printf("do-while文は必ず一度は実行します\n\n");
	} while (2 < 1);
	while (2 < 1);
	{
		printf("do-while文は最初から条件を満たしていない場合、一度も実行されません\n\n");
	}
	*/
//繰り返し while
	/*
    //条件を満たすまで同じ処理を繰り返す　while文
	int hp = 50;
	while (hp > 0) {//条件は終了条件ではなく継続条件
		printf("ダメージを受けた！\n");
		hp -= 8;
		printf("残りHP　%d\n", hp);
	}
	printf("死んでしまった...\n\n");

	//上のwhile文をfor文で置き換える
	for (int hp = 50; hp > 0;); {
		printf("ダメージを受けた！\n");
		hp -= 8;
		printf("残りhp　%d\n", hp);
	}
	printf("死んでしまった...\n\n");
	*/
//繰り返し　for
	/*
	//指定した回数同じ処理を繰り返す
	for (int i = 0; i < 16; i++) {
    //printf("%d回目のループ\n", i+1);
		//同じ計算をする処理はまとめておく
		int dispNum = (i + 1);

		if (dispNum % 2 == 0)
		{
			printf("%dは偶数\n", dispNum);
		}
		else {
			printf("%dは奇数\n", dispNum);
		}
	}*/
//偶数か奇数か
	/*
		if ((i + 1) % 2 == 0)//値が奇数か偶数か
		{
			printf("%dは偶数\n", i + 1);
		}
		else
		{
			printf("%dは奇数\n", i + 1);
		}*/
//ループ回数を数える
	/*
	int loopCount = 0; //ループ回数を数える

	//指定した回数同じ処理を繰り返す
	for (loopCount = 1; loopCount <= 5; loopCount++) {
		printf("%d回目のループ\n", loopCount);
	}
	*/