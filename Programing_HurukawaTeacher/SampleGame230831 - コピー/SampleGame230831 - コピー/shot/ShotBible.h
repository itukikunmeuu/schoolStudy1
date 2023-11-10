#pragma once
#include "ShotBase.h"
#include "Vec2.h"
class ShotBible :
    public ShotBase
{
public:
    ShotBible();
    virtual ~ShotBible();

    virtual void Init() override;
    virtual void Update() override;
    virtual void Draw() override;

    /// <summary>
/// 弾をスタートさせる
/// </summary>
/// <param name="pos">発射位置</param>
    virtual void Start(Vec2 pos) override;

private:
    //一定時間経過したら消すために精製してからのフレームを数える
    int m_frameCount;

    //プレイヤーから見てどの方向にあるか
    //弧度法で指定
    float m_angle;

};