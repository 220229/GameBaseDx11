#include "BulletE.h"
#include "Engine/Model.h"

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
}

//�X�V
void BulletE::Update()
{

	transform_.position_.x -= 0.2;
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