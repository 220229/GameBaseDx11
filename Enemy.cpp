#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), hModel_(-1)
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Model\\Enemy.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = {+10, (float)(rand() % 25 - 20), 0 };
	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 1.0f);
	AddCollider(collision);
}

//更新
void Enemy::Update()
{
    //transform_.position_.x -=0.05;
}

//描画
void Enemy::Draw()
{
    Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Enemy::Release()
{
}
int kill = 0;
//何かに当たった
void Enemy::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	//弾に当たったとき
	if (pTarget->GetObjectName() == "BulletP")
	{
		this->KillMe();
		pTarget->KillMe();
		kill = kill + 1;
	}
	if (kill >= 7)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
		kill = 0;
	}
}
