#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class ClearLogo : public GameObject
{
    int hPict_;    //画像番号
public:
    //コンストラクタ
    ClearLogo(GameObject* parent);

    //デストラクタ
    ~ClearLogo();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};