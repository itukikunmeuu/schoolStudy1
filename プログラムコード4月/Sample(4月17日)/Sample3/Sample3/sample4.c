#include<stdio.h>

int main(void)
{
	int num1 = 8;  //int; 整数（負の値も使える）
	float num2 = 1.5;  //float:　小数を扱いたい
	char num3 = 'A';  //char:  文字（半角一文字）を扱いたい

	//キャストの例
	printf("(int)num2 = %d\n", (int)num2);

	// int型にfloat型の値を代入
	printf("num1 + num2 = %f\n", num1 + num2);  //num1 + num2はfloat
    printf("num1 = %d\n", num1);

	int ans = num1 + num2;
	printf("ans = %d\n", ans);

	float ans2 = ans;
	printf("ans2 = %f\n", ans2);

	int num4 = 128;
	char num5 = 127; 
	printf("num4 + num5 = %d\n", num4 + num5); //mum4+num5は



	return  0;
}


	/*
	int a,b,c;
	b = 1;
	c = 5;

	b = c;
	a = b;

	//a = b = c;
    //a = b = 1;

	printf("a=%d\n", a);
	printf("b=%d\n", b);
	printf("c=%d\n", c);

	return 0;
}*/

/*int main(void)
{
	int ans;

	int a = 2;
	int b = 3;
	int c = 5;

	ans = a + b * c; //足し算よりも掛け算が優先される
	printf("%d + %d * %d = %d\n",a,b,c ,ans);
} */

/*int main(void)
{
	int a;
	int b;

	b = 5;

	b++;
    a = b;   //他人に見られても平気でわかりやすいものを
	
	printf("aの値は%dです\n", a);
	printf("bの値は%dです\n", b);
}*/


/*int main(void)
{
	int hp = 100;
	int enemyAttack = 10;

	//ダメージを受けた
	hp = hp - 10;
	printf("HP;%d\n", hp);
	//代入演算子を使用した書き方
	hp -= enemyAttack;

	printf("HP;%d\n", hp);

	//ビットシフトを試す
	int shiftTest = 100;
	printf("shiftTest %d\n", shiftTest << 1);  //左に1ビットシフト
	printf("shiftTest %d\n", shiftTest >> 1);  //右に1ビットシフト

	int num = 6;
	//インクリメント演算子　インクリメント
	num += 1;  //numに1を足してnumに代入する　num +1. num = mim+1と同じ

	//デクリメント演算子
	num--;  //numから1を引いてnumに代入する　num -= 1 , mum = num -1　と同じ
	printf("num;%d\n", num);



	return 0;
}*/

/*int main(void)
{
	printf("4/21の授業\n");

	int testnum = 16; //テスト用の数字

	int hp = 100;
	printf("プレイヤーのHP:%d\n", hp);

	//四則演算を行った結果を表示する
	printf("プレイヤーのHP+10: %d\n", testnum + 10);
	printf("プレイヤーのHP-10: %d\n", testnum - 10);
	printf("プレイヤーのHP*10: %d\n", testnum* 10);
	printf("プレイヤーのHP/10: %d\n", testnum/ 10);
	printf("プレイヤーのHP/10のあまり: %d\n", testnum % 10);

	//四則演算を行った結果を表示する
	printf("プレイヤーのHP+10: %d\n", hp + 10);
	printf("プレイヤーのHP-10: %d\n", hp - 10);
	printf("プレイヤーのHP*10: %d\n", hp * 10);
	printf("プレイヤーのHP/10: %d\n", hp / 10);
	printf("プレイヤーのHP/10のあまり: %d\n", hp % 10);

	printf("\n");  //見えにくいので改行

	//変数に値を代入する
	hp = 150;
	printf("プレイヤーのHP;%d\n", hp);

	//敵の攻撃力
	int enemyAttack = 24;

	//魔法を使って敵の攻撃力を半減させる
	enemyAttack = enemyAttack / 2;
	printf("魔法を使った！\n敵の攻撃力が%dになった。\n", enemyAttack);

	//ダメージを受けた　HPを減らしたい
	//HPを20減らしたい
	hp = hp - 20;
	printf("ダメージを%d受けた！\nプレイヤーのHP；%d\n",enemyAttack, hp);
	
	//HP符号を反転させる
	hp = -hp;
	printf("hp : %n\n", hp);
	hp = -hp;
	printf("hp : %n", hp);
	return 0;} */