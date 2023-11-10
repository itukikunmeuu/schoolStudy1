#pragma once


//プロトタイプ宣言

//勝ちを表示するための関数
void dispWin(void);
//負けを表示するための関数
void dispLose(void);
//グー、チョキ、パーを表示するための関数
void dispHandl(int hand);
//グーｖｓパーのように表示する関数
void dispBattle(int playerHand, int enemyHand);
//2-1 勝ちのような表示を行う関数
void dispResult(int win, int lose);
//ランダムな手(グーかチョキかパー)を生成して返す関数
int createRandHand(void);
//プレイヤーの手、敵の手を引数として返す
//勝ち；1　負け；-1　引き分け；0を返す
int getBattleResult(int PlayerHand, int enemyHand);