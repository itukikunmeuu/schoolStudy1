#include "DxLib.h"



//�萔
namespace
{
    //�����z�u
    constexpr int kStartPosX = 320;
    constexpr int kStartPosY = 240;
    //�ړ����x
    constexpr int kSpeed = 2;

}

class Player
{
public:
    int m_handle;   //�O���t�B�b�N�n���h��
    int m_posX;     //�\�����W��
    int m_posY;     //�\�����W�x
    bool m_isTurn;  //���E���]�t���O

    //�R���g���N�^�@���������m�ۂ������_�ŏ���ɌĂ΂��֐�
    Player();                   //�����Ȃ��R���X�g���N�^
    Player(int x, int y);       //�����ŏ����ʒu��ݒ�ł���R���X�g���N�^

    //�����o�[�֐�
    void init();
    void update();
    void draw();
};
#if false
//Player�N���X�̃R���X�g���N�^
Player::Player()
{
    //�O���t�B�b�N�̃��[�h
    m_handle = LoadGraph("data/player.png");
    m_posX = kStartPosX;
    m_posY = kStartPosY;
    //�O���t�B�b�N���]�t���O
    m_isTurn = false;
}
#endif

Player::Player(int x, int y)
{
    //�O���t�B�b�N�̃��[�h
    m_handle = LoadGraph("data/player.png");
    m_posX = x;
    m_posY = y;
    //�O���t�B�b�N���]�t���O
    m_isTurn = false;
}


//�����o�[�֐��̎���
//�֐����̑O�ɃN���X��::�������Ă���Ă��̃N���X��draw�֐��ł��A�Ɛ錾����
void Player::draw()
{
    if (m_isTurn)
    {
        DrawTurnGraph(m_posX, m_posY, m_handle, false);
    }
    else
    {
        DrawGraph(m_posX, m_posY, m_handle, false);
    }
}

void Player::init()
{
    //�O���t�B�b�N�̃��[�h
    m_handle = LoadGraph("data/player.png");
    m_posX = kStartPosX;
    m_posY = kStartPosY;
    //�O���t�B�b�N���]�t���O
    m_isTurn = false;
}

//Player�N���X�̃f�X�g���N�^
Player::~Player()
{
    //����������������Ƃ��ɕK���ǂ�łق�������������
    DeleteGraph(m_handle)
}



//�v���C���[�̍X�V

void Player::update()
{
    int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
    if (pad & PAD_INPUT_UP)
    {
        //��L�[��������Ă���
        m_posY -= kSpeed;  //������Ɉړ�������
    }
    if (pad & PAD_INPUT_DOWN)
    {
        //��L�[��������Ă���
        m_posY += kSpeed;  //������Ɉړ�������
    }
    if (pad & PAD_INPUT_LEFT)
    {
        //��L�[��������Ă���
        m_posX -= kSpeed;  //������Ɉړ�������
        m_isTurn = false;
    }
    if (pad & PAD_INPUT_RIGHT)
    {
        //��L�[��������Ă���
        m_posX += kSpeed;  //������Ɉړ�������
        m_isTurn = true;
    }
}

//�v���C���[�̕`��

void drawPlayer(Player player)

{
    if (player.m_isTurn)
    {
        DrawTurnGraph(player.m_posX, player.m_posY, player.m_handle, false);   //���E���]
    }
    else
    {
        DrawGraph(player.m_posX, player.m_posY, player.m_handle, false);
    }
}

// �v���O������ WinMain ����n�܂�܂�

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //�ꕔ�̊֐���Dxlib_Init()�̑O�Ɏ��s����K�v������
    ChangeWindowMode(true);

    if (DxLib_Init() == -1)        // �c�w���C�u��������������
    {
        return -1;            // �G���[���N�����璼���ɏI��
    }

    SetDrawScreen(DX_SCREEN_BACK);

    //�v���C���[
    Player player;
 //   Player player2(220, 240); //������ƌÂ�
    Player player2{ 420,340 };  //�ŐV�͔g������

    //�v���C���[�̏�����
    player.init();
    player2.init();
    Player playerTbl[4] =
    {
        Player(),
        Player(100, 200),
        Player(200, 200),
    };

        // �Q�[�����[�v
        while (ProcessMessage() != -1)
        {
            //���̃t���[���̊J�n�������o���Ă���
            LONGLONG start = GetNowHiPerformanceCount();
            // �`����s���O�ɉ�ʂ��N���A����
            ClearDrawScreen();
            //�Q�[������
            player.update();
            player2.update();

            player.update();
            //�`��
            player.draw();
            player2.draw();

            for (int i = 0; i < 4; i++)
            {
                playerTbl[i].draw();
            }
            //drawPlayer(player);
            player.draw();
            player2.draw();

            // ��ʂ��؂�ւ��̂�҂�
            ScreenFlip();

            //esc�L�[�ŏI��
            if (CheckHitKey(KEY_INPUT_ESCAPE))
            {
                break;
            }

            //FPS60�ɌŒ肷��
            while (GetNowHiPerformanceCount() - start < 16667)
            {

            }
        }


    //�O���t�B�b�N���������������
    DeleteGraph(player.m_handle);
    DxLib_End();                // �c�w���C�u�����g�p�̏I������
    return 0;                // �\�t�g�̏I�� 
}