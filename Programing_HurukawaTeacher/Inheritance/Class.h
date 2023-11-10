#pragma once
#include <iostream>
using namespace std;


//				　◇継承とは？◇
//　あるクラスを基に新しいクラスを作ることができる
//　これを継承という

//今回はClassBaseを基に新しいクラスを作成する
//基になるクラスのことを基底クラスと呼ぶ
class ClassBase
{
public:

	ClassBase() :
		m_num(0)
	{
		cout << "ClassBaseの引数なしコンストラクタ" << m_num << endl;

	}

	ClassBase(int num):
		m_num(num)
	{
		cout << "ClassBaseのコンストラクタ" << m_num << endl;
	}
	~ClassBase()
	{
		cout << "ClassBaseのデストラクタ" << m_num <<  endl;
	}

	void Func0()
	{
		cout << "ClassBase::Func0" << m_num << endl;
	}
	void Func1()
	{
		cout << "ClassBase::Func1" << m_num << endl;
	}
	void Func2()
	{
		cout << "ClassBase::Func2" << m_num << endl;
	}
	//pribateなメンバーはクラス外から参照できない
	//それは継承先のクラスでも同様
	//継承先のクラスが基底クラスの持つ変数を変更したい場合はよくある
private:
	//位置情報や攻撃力など、基底クラスに持たせて、
	//継承先でも変更を行い大変巣はいくらでもある

	//そういう場合はprotectedで宣言する
	//protectedな変数、関数はクラス外からは見えないが
	//継承先のクラスからは見ることができる

	//よくわからないあいだは基底クラスのメンバ変数は
	//すべてprotectedでいいと思う
protected:

	void ProtectedFunc();
	{
		cout << "protectedな関数" << endl;
	}

	int m_num;
};

//ClassBaseをもとに新しいクラスを作成する
//ClassBaseを継承して新しいクラスを作成する

//クラスの宣言時に継承元となるクラスを指定する必要がある
class ClassChild0 : public ClassBase
{
public:
	ClassChild0()
	{
		//基底クラスのコンストラクタを明示的に呼ばない場合。
		//継承先のクラスの公司とラスタが呼び出し前に
		//引数なしの継承先コンストラクタが呼び出される


		cout << "ClassChild0のコンストラクタ" << endl;
	}
	ClassChild0(int num):
		ClassBase(num) //継承元クラスのコンストラクタを明示的に呼ぶ
	{
		cout << "ClassChild0の引数付きコンストラクタ" << endl;

	}
	~ClassChild0()
	{
		cout << "ClassChild0のデストラクタ" << endl;

		//継承先のデストラクタが呼ばれた後、
		//継承先のデストラクタが呼ばれる
	}

	//同じくClassBaseを継承したクラス
	class ClassChild1 : public ClassBase
	{
	public:
		ClassChild1()
		{
			cout << "ClassChild1のコンストラクタ" << endl;
		}
		~ClassChild1()
		{
			cout << "ClassChild1のデストラクタ" << endl;
		}

		//基底クラスのFunc0を使うのではなく、
		//このクラスの特殊な処理を行いたい
		void Func0()
		{
			cout << "ClassChild1の特殊なFunc0" << endl;
			//protectedな変数、関数は継承先から呼び出すことができる
			m_num = 999;
			ProtectedFunc();
		}
	};

};
