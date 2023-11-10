
#include "DxLib.h"



#define ENEMY_NUM    5



        typedef struct Player
    {
        int handle;
        float x;
        float y;
    }Player;




    void drawPlayer(Player player)
    {
        DrawGraph((int)player.x, (int)player.y, player.handle, 0);



    }



    typedef struct Enemy
    {
        int handle;
        float x;
        float y;
        float moveX;
        float moveY;

    }Enemy;



    // �v���O������ WinMain ����n�܂�܂�
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    {
        // �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
        ChangeWindowMode(1);



        if (DxLib_Init() == -1)        // �c�w���C�u��������������
        {
            return -1;            // �G���[���N�����璼���ɏI��
        }



        SetDrawScreen(DX_SCREEN_BACK);



        Player player;



        // �v���C���[�֘A�̏��
        player.handle = LoadGraph("data/player.png");
        player.x = 320.0f;
        player.y = 240.0f;



        // �G�֘A�̏��
    //    int enemyHandle = LoadGraph("data/enemy.png");
        int tempHandle = LoadGraph("data/enemy.png");



        Enemy enemy;



        enemy.handle[ENEMY_NUM];
        float enemyX[ENEMY_NUM];
        float enemyY[ENEMY_NUM];
        float enemyMoveX[ENEMY_NUM];
        float enemyMoveY[ENEMY_NUM];
        // �G�̏�����
        for (int i = 0; i < ENEMY_NUM; i++)
        {
            enemyX[i] = (float)(GetRand(640 - 32));
            enemyY[i] = (float)(GetRand(480 - 32));
            enemyMoveX[i] = 2.5f;
            if (GetRand(1))    enemyMoveX[i] *= -1.0f;
            enemyMoveY[i] = 2.5f;
            if (GetRand(1))    enemyMoveY[i] *= -1.0f;
        }



        // �Q�[�����[�v
        while (ProcessMessage() != -1)
        {
            // �`����s���O�ɉ�ʂ��N���A����
            ClearDrawScreen();



            // update
            int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
            if ((padState & PAD_INPUT_UP) != 0)        // ��L�[������Ă���
            {
                player.y -= 2.5f;
                if (player.y < 0)    // ��ʊO�ɏo�悤�Ƃ���
                {
                    player.y = 0;
                }
            }
            if ((padState & PAD_INPUT_DOWN) != 0)    // ���L�[������Ă���
            {
                player.y += 2.5f;
                if (player.y > 480 - 32)
                {
                    player.y = 480 - 32;
                }
            }
            if ((padState & PAD_INPUT_LEFT) != 0)    // ���L�[������Ă���
            {
                player.x -= 2.5f;
                if (player.x < 0)
                {
                    player.x = 0;
                }
            }
            if ((padState & PAD_INPUT_RIGHT) != 0)    // �E�L�[������Ă���
            {
                player.x += 2.5f;
                if (player.x > 640 - 32)
                {
                    player.x = 640 - 32;
                }
            }



            // �G��update
            for (int i = 0; i < ENEMY_NUM; i++)
            {
                enemyX[i] += enemyMoveX[i];
                enemyY[i] += enemyMoveY[i];
                if (enemyX[i] < 0)
                {
                    enemyX[i] = 0;
                    enemyMoveX[i] *= -1.0f;
                }
                if (enemyX[i] > 640 - 32)
                {
                    enemyX[i] = 640 - 32;
                    enemyMoveX[i] *= -1.0f;
                }
                if (enemyY[i] < 0)
                {
                    enemyY[i] = 0;
                    enemyMoveY[i] *= -1.0f;
                }
                if (enemyY[i] > 480 - 32)
                {
                    enemyY[i] = 480 - 32;
                    enemyMoveY[i] *= -1.0f;
                }
            }
            // draw
            drawPlayer(player);
            // �G�̕`��
            for (int i = 0; i < ENEMY_NUM; i++)
            {
                enemyHandle[i] = tempHandle;
                DrawGraph((int)enemyX[i], (int)enemyY[i], enemyHandle[i], 0);
            }



            // ��ʂ��؂�ւ��̂�҂�
            ScreenFlip();
        }



        DeleteGraph(player.handle);
        DeleteGraph(tempHandle);



        DxLib_End();                // �c�w���C�u�����g�p�̏I������



        return 0;                // �\�t�g�̏I�� 
    }