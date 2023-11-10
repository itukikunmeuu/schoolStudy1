/**void transSeconds(int sec) {
	int aHor, aMin, aSec;

	//教科書通り、それぞれの計算を1行で書く
//	aHor = sec / (60 * 60); //時間を求める
//	aMin = (sec % (60 * 60)) / 60; //分を求める
//	aSec = sec % 60; //秒を求める

	int tempSec = sec;			//temp:temporaryの略　一時的にデータを保存しておく
	aHor = tempSec / (60 * 60); //時間の計算
	tempSec %= (60 * 60);       //時間の部分を取り除く
	aMin = tempSec / 60;		//分の計算
	tempSec %= 60;
	aSec = tempSec;             //秒（そのまま）

	printf("%d秒は、%d時間%d分%d秒です。\n", sec, aHor, aMin, aSec);

	return;
}*/