#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "BulletP.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Model\\Player.fbx");
    assert(hModel_ >= 0);
    transform_.position_.x = -10;
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
    AddCollider(collision);

}
float spowncooldown = 0;
//更新
void Player::Update()
{
    //Wが押されていたら
    if (Input::IsKey(DIK_W))
    {
        //何らかの処理
        transform_.position_.y += 0.2;
    }
    //Sが押されていたら
    if (Input::IsKey(DIK_S))
    {
        //何らかの処理
        transform_.position_.y -= 0.2;
    }

    if (Input::IsKeyDown(DIK_SPACE))
    {
        BulletP* p = Instantiate<BulletP>(this->GetParent());
        p->SetPosition(this->transform_.position_);//プレイヤーの位置
    }
    if (Input::IsKeyDown(DIK_SPACE))
    {
        BulletP* p = Instantiate<BulletP>(this->GetParent());
        p->SetPosition(this->transform_.position_);//プレイヤーの位置
    }
}

//描画
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}