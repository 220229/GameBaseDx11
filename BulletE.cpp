#include "BulletE.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
BulletE::BulletE(GameObject* parent)
	:GameObject(parent, "BulletE"), hModel_(-1)
{
}

//デストラクタ
BulletE::~BulletE()
{
}

//初期化
void BulletE::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Model\\BulletE.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.4f);
	AddCollider(collision);
}

//更新
void BulletE::Update()
{

	transform_.position_.x -= 0.2;
	if (transform_.position_.x <= -20)
	{
		this->KillMe();
	}
}

//描画
void BulletE::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void BulletE::Release()
{
}

//何かに当たった
void BulletE::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	//弾に当たったとき
	if (pTarget->GetObjectName() == "BulletP")
	{
		this->KillMe();
		pTarget->KillMe();
	}
}