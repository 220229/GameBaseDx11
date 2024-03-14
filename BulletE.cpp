#include "BulletE.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
BulletE::BulletE(GameObject* parent)
	:GameObject(parent, "BulletE"), hModel_(-1)
{
}

//�f�X�g���N�^
BulletE::~BulletE()
{
}

//������
void BulletE::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model\\BulletE.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.4f);
	AddCollider(collision);
}

//�X�V
void BulletE::Update()
{

	transform_.position_.x -= 0.2;
	if (transform_.position_.x <= -20)
	{
		this->KillMe();
	}
}

//�`��
void BulletE::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void BulletE::Release()
{
}

//�����ɓ�������
void BulletE::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	//�e�ɓ��������Ƃ�
	if (pTarget->GetObjectName() == "BulletP")
	{
		this->KillMe();
		pTarget->KillMe();
	}
}