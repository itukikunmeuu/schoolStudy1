#pragma once



class Player
{
public:
    Player();  //生成時に呼ばれる
    ~Player(); //消除時に呼ばれる



    void init();
    void update();
    void draw();



    //小さい関数はベッターに中身を書くことも多い

    //set,get関数はクラス実装しているとよく出てくるので覚えよう
    //get関数はconstしてやる癖をつけよう
    void setPosX(int x) { m_posX = x; }
    int getPosX() const { return m_posX; }


    int getPosY() const { return m_posY; }

    //半径の取得
    int getRadius() const;


    //メンバー変数はprivate
private:
    int m_posX;
    int m_posY;

};

