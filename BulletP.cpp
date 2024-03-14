#include "BulletP.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h";

//�R���X�g���N�^
BulletP::BulletP(GameObject* parent)
    :GameObject(parent, "BulletP"), hModel_(-1)
{
}

//�f�X�g���N�^
BulletP::~BulletP()
{
}

//������
void BulletP::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model\\BulletP.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.4f);
	AddCollider(collision);
}

//�X�V
void BulletP::Update()
{

	transform_.position_.x += 0.2;
}

//�`��
void BulletP::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void BulletP::Release()
{
}

//�����ɓ�������
void BulletP::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	//�G�ɓ��������Ƃ�
	if (pTarget->GetObjectName() == "Enemy")
	{
		this->KillMe();
		pTarget->KillMe();
	}
}