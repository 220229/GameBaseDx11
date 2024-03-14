#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "BulletP.h"
#include "Engine/SphereCollider.h"
#include "BulletE.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"

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
    transform_.position_.x = -13;
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
    AddCollider(collision);

}

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
    if (transform_.position_.y < -15.0)
    {
        transform_.position_.y = -15;
    }
    if (transform_.position_.y > 15.0)
    {
        transform_.position_.y = 15;
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

//何かに当たった
void Player::OnCollision(GameObject* pTarget)
{
    //当たったときの処理
    //弾に当たったとき
    if (pTarget->GetObjectName() == "BulletE")
    {
        this->KillMe();
        pTarget->KillMe();
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
    }
}