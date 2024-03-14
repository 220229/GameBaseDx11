#include "BulletP.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h";

//コンストラクタ
BulletP::BulletP(GameObject* parent)
    :GameObject(parent, "BulletP"), hModel_(-1)
{
}

//デストラクタ
BulletP::~BulletP()
{
}

//初期化
void BulletP::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Model\\BulletP.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.4f);
	AddCollider(collision);
}

//更新
void BulletP::Update()
{

	transform_.position_.x += 0.2;
}

//描画
void BulletP::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void BulletP::Release()
{
}

//何かに当たった
void BulletP::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	//敵に当たったとき
	if (pTarget->GetObjectName() == "Enemy")
	{
		this->KillMe();
		pTarget->KillMe();
	}
}