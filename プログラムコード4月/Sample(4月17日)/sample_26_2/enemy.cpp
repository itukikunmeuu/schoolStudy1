Enemy::Enemy() :
	m_handle(LoadGraph("data/obj.png")),
	m_posX(320),
	m_posY(240)
{

}
//デストラクタ
Enemy::~Enemy()
{
	DeleteGraph(m_handle);
}

void Enemy::init()
{
}
void Enemy::draw()
{
	DrawGraph(m_posX, m_posY, m_handle, false);
}