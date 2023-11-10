
#include"enemy.h"
#include"DxLib.h"

//�萔���`
namespace
{
    //�����ʒu
    constexpr int kDefaultPosX = 320;
    constexpr int kDefaultPosY = 240;
    //���a
    constexpr int kRadius = 48;
    //�F
    const unsigned int kDefaultColor = GetColor(200, 200, 200);
    //�������Ă���ꍇ�̐F
    const unsigned int kHitColor = GetColor(255, 32, 32);
}

//�����o�ϐ��ɃA�N�Z�X�������ꍇ��
//public�ȃ����o�֐����o�R���ĕύX����
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
    //�����͑S�R���Ȃ���OK ������ƗV��
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
    //�s���Ȓl�ݒ肳�ꂽ�ꍇ�A�s������Ȃ��悤�ɂ�����ł���
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