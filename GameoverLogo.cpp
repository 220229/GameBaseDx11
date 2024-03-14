#include "GameoverLogo.h"
#include "Engine/Image.h"

//コンストラクタ
GameoverLogo::GameoverLogo(GameObject* parent)
    :GameObject(parent, "GameoverLogo"), hPict_(-1)
{
}

//デストラクタ
GameoverLogo::~GameoverLogo()
{
}

//初期化
void GameoverLogo::Initialize()
{
    //画像データのロード
    hPict_ = Image::Load("GameoverLogo.png");
    assert(hPict_ >= 0);
}

//更新
void GameoverLogo::Update()
{
}

//描画
void GameoverLogo::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//開放
void GameoverLogo::Release()
{
}
