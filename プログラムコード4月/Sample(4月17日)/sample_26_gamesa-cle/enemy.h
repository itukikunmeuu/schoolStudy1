#pragma once
//�N���X�̐錾
class Enemy
{
public:
    Enemy();
    ~Enemy();

    void init();
    void update();
    void draw();

    //�����o�[�ϐ��𒼐ڕύX�������ꍇ��
    //public�ȃ����o�֐����o�R���ĕύX����
    //�s���Ȓl��ݒ肳�ꂽ�ꍇ�A�s������Ȃ��悤�ɂ�����ł���
    void setPosX(int x);
    int getPosX() { return m_posX; }
    int getPosY() { return m_posY; }

    //���a�̎擾
    int getRadius();
    
    //�������Ă��邩�ǂ�����ݒ�
    //�������Ă��Ȃ��ꍇ���}�C�t���[��false��ݒ肷��
    void setHit(bool isHit) { m_isHit = isHit; }

    //�����o�[�ϐ���private
private:
    int m_posX;
    int m_posY;

    //�������Ă��邩�������Ă��Ȃ����t���O
    bool m_isHit;
};