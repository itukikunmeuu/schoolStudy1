
#include"enemy.h"
#include"DxLib.h"

//定数を定義
namespace
{
    //初期位置
    constexpr int kDefaultPosX = 320;
    constexpr int kDefaultPosY = 240;
    //半径
    constexpr int kRadius = 48;
    //色
    const unsigned int kDefaultColor = GetColor(200, 200, 200);
    //当たっている場合の色
    const unsigned int kHitColor = GetColor(255, 32, 32);
}

//メンバ変数にアクセスしたい場合は
//publicなメンバ関数を経由して変更する
Enemy::Enemy() :
    m_posX(kDefaultPosX),
    m_posY(kDefaultPosY),
    m_isHit(false)
{

}

Enemy::~Enemy()
{

}

void Enemy::init()
{

}

void Enemy::update()
{

}

void Enemy::draw()
{
    unsigned int color = kDefaultColor;
    //ここは全然やらなくてOK ちょっと遊ぶ
    int x = m_posX;
    int y = m_posY;

    if (m_isHit)
    {
        x += GetRand(5) - 1;
        y += GetRand(5) - 1;
        color = kHitColor;
    }
 //   DrawCircle(m_posX, m_posY, kRadius, kDefaultColor, true);
    DrawCircle(x, y, kRadius, color, true);
}


void Enemy::setPosX(int x)
{
    //不正な値設定された場合、不正じゃないようにしたりできる
    m_posX = x;
    //
    if (m_posX < 0)
    {
        m_posX = 0;
    }
    if (m_posX > 640)
    {
        m_posX = 640;
    }
}

int Enemy::getRadius()
{
    return kRadius;
}