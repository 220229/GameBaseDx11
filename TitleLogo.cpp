#include "TitleLogo.h"
#include "Engine/Image.h"

//コンストラクタ
TitleLogo::TitleLogo(GameObject* parent)
    :GameObject(parent, "TitleLogo"), hPict_(-1)
{
}

//デストラクタ
TitleLogo::~TitleLogo()
{
}

//初期化
void TitleLogo::Initialize()
{
    //画像データのロード
    hPict_ = Image::Load("TitleLogo.png");
    assert(hPict_ >= 0);
}

//更新
void TitleLogo::Update()
{
}

//描画
void TitleLogo::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//開放
void TitleLogo::Release()
{
}