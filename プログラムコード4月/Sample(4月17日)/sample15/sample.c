#include<stdio.h> //printf,scanf_s
#include<stdlib.h> //ramd(),srand()

//文字列の連結
//"abc"と"def"を連結して"abcdef"という文字列に変換する
//何に使うの？

//ゲームではファイルパスの作成などに使ったりする
//ファイルパス？　　ファイルのコンピュータ上の置き場所
//　C:\user\teacher\desktop\fukuoka\プログラミング1￥■課題.txt


int main(void)
{
	char str1[100] = "Hello!";
	char str2[] = "G_Gengo";

	//(結合する文字列、文字列を入れることができるサイズ、結合する文字列2)
	strcar_s(str1, sizeof(str1), str2);

	printf("%s\n", str1);

	return 0;
}

//sizeof演算子を使用する
//データ型や配列の合計バイト数を取得することができる
/*
int main(void)
{
	printf("実行環境ではint型は%dバイトです\n", sizeof(int));
	printf("実行環境ではint型は%dバイトです\n", sizeof(char));
	printf("実行環境ではint型は%dバイトです\n", sizeof(float));
	//char　は1バイト
	//つまりstr[]のサイズが10バイトなら配列の要素数は10だとわかる
	//char str[] = "C_Gengo"l
	//printf("配列strのばいとすうは%dです\n",(int)sizeof(str))

	char str[100];

	printf("文字列を半角で入力してください\n");
	scanf_s("%s", str, 100);

	printf("配列strのバイト数は%dです\n", (int)sizeof(str));

	printf("文字列の長さは%dです\n", srtlen(str));

	return 0;
}*/
//strlen()で文字列の長さを計測する
/*
int main(void)
{
	char str[100];
	int length;

	printf("文字列を半角で入力してください\n");
	scanf_s("%s", str, 100);

	//strlen()関数、文字列の長さを取得するための関数
	//引数として文字列を指定する
	// 文字列の長さを戻り値として返してくれる
	length = strlen(str);

	//strlen()関数が返してくれる長さにNULL文字(\0)は含まれない
	printf("%sは%d文字です\n", str, length);

	return 0;
}*/
// scanf_s()を使用してキーボードから入力された文字を配列に格納する
/*
int main(void)
{
	//キーボードから受け取る文字列を格納するための配列
	char str[100];

	printf("文字列を半角で入力してください\n");

	scanf_s("%s", str,100);  //&strではない
	printf("%sが入力されました\n", str);

	//参考　scanf_sで数値入力
	int num = 0;
	scanf_s("%d", &num);
	return 0;
}*/
//文字列の初期化
/*
int main(void)
{
	char str[] = "C_Gengo";

	//str = "D_Gengo"; //エラー

//	printf(str);
	printf("文字列は%sです\n", str);
	return 0;
}*/
//文字列
/*
int main(void)
{
	char str[8];

	str[0] = 'c';
	str[1] = '_';
	str[2] = 'G';
	str[3] = 'e';
	str[4] = 'n';
	str[5] = 'g';
	str[6] = 'o';
	str[7] = '\0'; //\nとか\tの親戚

	printf(str); //printfでcharの配列を指定する場合は配列名のみを引数とする
	printf("\n");

	char str2[5];
	str2[0] = 'A';
	str2[1] = 'B';
	str2[2] = '\0'; //文字列の途中？にＮＵＬＬ文字
	str[3] = 'C';
	str2[4] = 'D';

}
*/
//文字
/*
int main(void)
{
	//'A' シングルコーテーションの中に半角一文字
	//→文字　char型に保存する

	//"文字列"　ダブルコーテーションの中に文字複数
	//→文字列　printf等を使用する
	//文字列はString Textといった呼ばれ方をすることもある

	//"A" ダブルコーテーションの中に半角1文字
	//これも文字列

	//今までもprintf()の関数の引数として文字列を指定していた
	printf("表示したい文字列\n");

	return 0;
}*/