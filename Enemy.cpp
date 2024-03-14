#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"
#include "BulletE.h"

int kill = 0;
float spowncooldown = 0;

//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//������
void Enemy::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model\\Enemy.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { +13, (float)(rand() % 25 - 20) + 10, 0 };
	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 1.0f);
	AddCollider(collision);
	kill = 0;
}


//�X�V
void Enemy::Update()
{
	transform_.position_.y -= (float)(rand() % 15 + 1) / 60;
	spowncooldown += 0.1;
	if (transform_.position_.y <= -15)
	{
		transform_.position_.y = 15;
	}
	if (spowncooldown >= 6)
	{
		BulletE* e = Instantiate<BulletE>(this->GetParent());
		e->SetPosition(this->transform_.position_);//�G�̈ʒu
		spowncooldown = 0;
	}
}

//�`��
void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Enemy::Release()
{
}

//�����ɓ�������
void Enemy::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	//�e�ɓ��������Ƃ�
	if (pTarget->GetObjectName() == "BulletP")
	{
		this->KillMe();
		pTarget->KillMe();
		kill = kill + 1;
	}
	while (kill >= 7)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
		kill = 0;
	}
}
