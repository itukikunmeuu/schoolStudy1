[9:45] �]���@����

#include "DxLib.h"





typedef struct Pos



{



    float x;



    float y;



}Pos;





// �\���̂̐錾



// �v���C���[�Ǘ��p�̍\����



typedef struct Player



{



    int handle;



    Pos pos;



}Player;





// �v���C���[��`�ʂ��邽�߂̊֐�



void drawPlayer(Player pl)



{



    //    player.handle;



    //    player.pos.x;



    //    player.pos.y;



    DrawGraph((int)pl.pos.x, (int)pl.pos.y, pl.handle, 0);



}





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





    // �v���C���[�֘A�̏��



    Player player;





    player.handle = LoadGraph("data/player.png");    // vcxproj�Ɠ����t�H���_�ɂ���摜��ǂݍ���



    player.pos.x = 320.0f;



    player.pos.y = 240.0f;







    // �Q�[�����[�v



    while (ProcessMessage() != -1)



    {



        // �`����s���O�ɉ�ʂ��N���A����



        ClearDrawScreen();





        // update



        int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);



        if ((padState & PAD_INPUT_UP) != 0)        // ��L�[������Ă���



        {



            player.pos.y -= 2.5f;



            if (player.pos.y < 0)    // ��ʊO�ɏo�悤�Ƃ���



            {



                player.pos.y = 0;



            }



        }



        if ((padState & PAD_INPUT_DOWN) != 0)    // ���L�[������Ă���



        {



            player.pos.y += 2.5f;



            if (player.pos.y > 480 - 32)



            {



                player.pos.y = 480 - 32;



            }



        }



        if ((padState & PAD_INPUT_LEFT) != 0)    // ���L�[������Ă���



        {



            player.pos.x -= 2.5f;



            if (player.pos.x < 0)



            {



                player.pos.x = 0;



            }



        }



        if ((padState & PAD_INPUT_RIGHT) != 0)    // �E�L�[������Ă���



        {



            player.pos.x += 2.5f;



            if (player.pos.x > 640 - 32)



            {



                player.pos.x = 640 - 32;



            }



        }





        // draw



        DrawGraph((int)player.pos.x, (int)player.pos.y, player.handle, 0);



        drawPlayer(player);





        // ��ʂ��؂�ւ��̂�҂�



        ScreenFlip();



    }





    DeleteGraph(player.handle);





    DxLib_End();                // �c�w���C�u�����g�p�̏I������





    return 0;                // �\�t�g�̏I��



}