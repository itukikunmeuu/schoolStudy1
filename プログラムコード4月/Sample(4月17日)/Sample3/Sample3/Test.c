/*画面へ文字列を表示するプログラム*/
#include<stdio.h>
int main(void)
{
	int a = 1;
	int b = -1;
	printf("a = %d\n", a);
	printf("+a = %d\n", +a); //+(1)
	printf("-a = %d\n", -a); //-(1)

	printf("b = %d\n", b);
	printf("+b = %d\n", +b);  //+(-1)
	printf("-b = %d\n", -b);  //-(-1)

	printf("a+b = %d\n", a+b);

 


//	printf("1 + 2 = %d\n", 1 + 2);        //足し算
//	printf("3 - 1 = %d\n", 3 - 1);        //引き算
//	printf("5 * 3 = %d\n", 5 * 3);        //掛け算
//	printf("7 / 2 の余り　%d\n", 7 % 2);  //割り算（余りを出す場合）

//	printf("7 / 2 = %d\n", 7 / 2);        //割り算（余りを出さなくてもいい場合）

	return 0;

}

/*
int main(void)
{
	//要素後を大文字にすること　キャメルケース
	int recoveryItemNum = 0;   //回復アイテムの数
	//文と文の間に＿をつけること スネークケース
	int recovery_item_num = 0;
	//覚えてほしい変数の方
	unsigned int num = 123;     //　iny 整数型
	float dig = -4.0;           // float 小数
	char chr = '3';             //　char 文字1文字（半角１文字）

	/*
	
	'B'         //文字（１文字）
	'3'         //文字（１文字）

    "ABC"       //文字列（文字列の並び）
	"C言語"     //全角を含む文字列
	'あ'        //全角文字は１文字ではない
	"Z"         //文字列
	
	

//	printf("num = %d\n", num);
//	printf("dig = %f\n", dig);
//	printf("chr = %c\n", chr+1);

//	printf("chr = %d\n", chr);
	//変数の宣言
	int test;

	int test2;
	int test3;
    test2 = 120;
	test3 = 240;

	test = test2; //＝は計算結果ではなく数字を代入するということ
//	printf("test = %d\n", test);
    test = test3;
//	printf("test = % d\n", test);

/*	int test = 0x7c;

	printf("test = %d\nabc\n. test");

	printf("%d\t%d\t%d\n"., 1, 2, 3);
	printf("%d\t%d\t%d\n"., 10, 20, 30);

	printf("\\t\n");
	printf("\")
	
	




	return 0;
} */
