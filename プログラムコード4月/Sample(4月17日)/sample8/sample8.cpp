#include<stdio.h>

//"関数が実行されました\n"と表示するための関数
void dispPrintf(void) {
	printf("関数が実行されました\n");
	return;
}

//因数として渡されたｘの値と
//それに1を足した値を表示するための関数
void f(int x) {
	printf("渡された変数の値は%dです\n", x);
	x++;
	printf("1を足した値は%dになります\n", x);
	return;
}

int main(void)
{
//	printf("プログラムが開始されました\n");
//	dispPrintf();
//	printf("プログラムを終了します\n");
	f(3);


	return 0;
}