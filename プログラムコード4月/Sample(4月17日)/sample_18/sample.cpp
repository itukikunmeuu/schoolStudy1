#include<stdio.h>

//テストの成績データ構造体
typedef struct Test
{
	int kokugo;
	int sansuu;
	int rika;
	int syakai;
}Test;

//生徒のデータ構造体
typedef struct Student
{
	int no;
	float height;
	float weight;
	//構造体を構造体のメンバーとして持つ
	Test exam;
}Student;

int main(void)
{
	Student student2 = { 2,169.5f,54.5f,{80,70,90,65} };

	printf("2人目の生徒の出席番号は%dです\n", student2.no);
	printf("2人目の生徒の身長は%fcmです\n", student2.height);
	printf("2人目の生徒の算数の点数は%dです\n", student2.exam.sansuu);

	return 0;
}

//typedefを用いた構造体宣言
/*
typedef struct Student
{
	int no;
	float height;
	float weight;
}Student;

int main(void)
{
	Student student1 = {1, 170.5f,58.0f};

	printf("1人目の生徒の出席番号は%dです\n", student1.no);
	printf("1人目の生徒の身長は%fcmです\n", student1.height);
	printf("1人目の生徒の体重は%fkgです\n", student1.weight);

	return 0;
}*/

//構造体の名前つけ
/*
//生徒のデータ管理用構造体の定義

//Student でも　student でもどちらでも〇　ややこしくなるから区別付けのため大文字と小文字に分ける
typedef struct Student
{
	int no;
	float height;
	float weight;
}Student;
//名前の変更　変更するとそのあとの構造体で簡単にした構造体を使用することができる
//	typedef struct Student Student;

int main(void)
{
	//初期化なしの構造体変数の宣言
	Student student1 = {1,170.5f,58.0f};
	//初期化付きの構造体変数の宣言
	struct Student student2 = {2,169.0f,54.5f};

	//構造体に構造体を代入する
	student1 = student2;

	printf("1人目の生徒の出席番号は%dです\n", student1.no);
	printf("1人目の生徒の身長は%fcmです\n", student1.height);
	printf("1人目の生徒の体重は%fkgです\n", student1.weight);

	return 0;
}*/

//構造体の使い方
/*
int main(void)
{
//	int num; //型名　変数名；
//	struct Sudent student1; //struct 構造体名　変数名;
	//初期化付きの構造体変数の宣言
	struct Sudent student1 = { 1,170.5f,58.0f };

	//.	を使用して構造体のメンバにアクセスする
	student1.height = 170.5f;

	return 0;
}*/