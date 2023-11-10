#pragma once
//クラスの宣言
class Enemy
{
public:
    Enemy();
    ~Enemy();

    void init();
    void update();
    void draw();

    //メンバー変数を直接変更したい場合は
    //publicなメンバ関数を経由して変更する
    //不正な値を設定された場合、不正じゃないようにしたりできる
    void setPosX(int x);
    int getPosX() { return m_posX; }
    int getPosY() { return m_posY; }

    //半径の取得
    int getRadius();
    
    //当たっているかどうかを設定
    //当たっていない場合もマイフレームfalseを設定する
    void setHit(bool isHit) { m_isHit = isHit; }

    //メンバー変数はprivate
private:
    int m_posX;
    int m_posY;

    //当たっているか当たっていないかフラグ
    bool m_isHit;
};