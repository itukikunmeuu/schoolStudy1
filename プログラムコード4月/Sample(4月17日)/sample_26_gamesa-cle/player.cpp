#include "player.h"
#include "DxLib.h"

//�萔�̐錾
namespace
{
    constexpr int kRadius = 16;
}

//�֐��̎���
Player::Player() :
    m_posX(0),
    m_posY(0)
{

}

Player::~Player()
{

}

void Player::init()
{

}

void Player::update()
{
    GetMousePoint(&m_posX, &m_posY);
}

void Player::draw()
{
    DrawCircle(m_posX, m_posY, 16, GetColor(255, 255, 255), true);
}

int Player::getRadius() const
{
    return kRadius;
}