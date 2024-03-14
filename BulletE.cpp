#include "BulletE.h"
#include "Engine/Model.h"

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
}

//更新
void BulletE::Update()
{

	transform_.position_.x -= 0.2;
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