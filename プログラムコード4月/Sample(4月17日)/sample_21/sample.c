#include<stdio.h>

//定数
#define BUFF_NONE 0		//バフなし
#define BUFF_ATTCK 1	//攻撃力アップ
#define BUFF_SPEED 2	//移動力アップ
#define BUFF_DEF 3		//防御力アップ

//プレイヤーへのバフの種類
typedef enum Buff
{
	NONE,		//なし
	ATTACK,		//攻撃力
	SPEED,		//移動速度
	DEF,		//防御力
}Buff;

//ステータスアップ情報を持つ共用体
typedef union BuffEffect
{
	int attack;		//攻撃力アップ量
	float speed;	//移動速度上昇量
	int def;		//防御力アップ量
	//...			//バフの種類が消えたらメンバも増える
}BuffEffect;

//プレイヤー構造体
typedef struct Player
{
	int hp;

	//バフ効果（ステータスアップ）
	//いくつかのステータスアップがあるが、（攻撃力、素早さ等...）
	//一つのみ有効（攻撃力のステータスがついているときに素早さがつくと攻撃力は消える）
	//新しいバフがつくと古いのは消える
	Buff buffType;			//現在のバフの種類
	BuffEffect buffEffect;  //ステータスアップ情報


}Player;

int main(void)
{
	//データ型
	//int型　整数を入れる
	//float型　小数を入れる
	//char型　文字を一文字入れる

	//列挙体であるBuff型;列挙体で定義した定数
	Buff bf;
	bf = NONE;
	bf = ATTACK;
	bf = SPEED;
	bf = DEF;
	bf = 10;  //ビルドは通るがよくない


	Player player;
	//初期化
	player.hp = 100;			
	player.buffType = BUFF_NONE;			

	//攻撃力バフ
	player.buffType = ATTACK;			//攻撃力UPに設定
	player.buffEffect.attack = BUFF_ATTCK;		//攻撃力の上昇量を設定


	//移動速度バフ
	player.buffType = SPEED;			//移動速度UPに設定
	player.buffEffect.speed = BUFF_SPEED;    //移動速度の上昇量を設定

	switch(player.buffType)
	{
	case NONE:
		break;
	case ATTACK:
		prinrf("攻撃力が%d上がっっている\n", player.buffEffect.attack);
		break;
	case SPEED:
		prinrf("移動速度が%d上がっっている\n", player.buffEffect.speed);
		break;
	case DEF:
		prinrf("防御力が%d上がっっている\n", player.buffEffect.def);
		break;
	}


	return 0;
}