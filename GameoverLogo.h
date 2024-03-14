#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class GameoverLogo : public GameObject
{
    int hPict_;    //画像番号
public:
    //コンストラクタ
    GameoverLogo(GameObject* parent);

    //デストラクタ
    ~GameoverLogo();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};