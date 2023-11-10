#pragma once
//なぜわざわざクラスのメンバをprivateにするの？
//すべてpublicなら便利では？

//const　値をいじれないようにする
//値をいじれたほうが便利　→間違えていじることを防ぐためにconstでそもそもいじれないようにする

//・クラスの処理はクラス自身にやらせる
//・外から勝手に値をいじられないようにする
//例,敵を非表示にしたい　勝手に画面買いの座標に移動させる、みたいなことが発生する　→敵は生きている

class Enemy
{
public:
	//コントラスタ、デストラクタは特殊なことをしない限りpublic
	Enemy();
	~Enemy();

	//クラス外から使いたい（今回はWIN　MAINで使う）ものはpublic
	void init();
	//	void update();
	void draw();

	//クラス外からメンバ変数を変更したい場合はpuclicなメンバ関数を通す
	void setPos(int x, int y);


private:
	//メンバ変数はすべてprivate
	int m_handle;
	int m_posX;
	int m_posY;
};