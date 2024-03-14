#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

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
	transform_.position_ = {+10, (float)(rand() % 25 - 20), 0 };
	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 1.0f);
	AddCollider(collision);
}

//�X�V
void Enemy::Update()
{
    //transform_.position_.x -=0.05;
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
	}
}
