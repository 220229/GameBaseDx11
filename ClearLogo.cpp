#include "ClearLogo.h"
#include "Engine/Image.h"

//�R���X�g���N�^
ClearLogo::ClearLogo(GameObject* parent)
    :GameObject(parent, "ClearLogo"), hPict_(-1)
{
}

//�f�X�g���N�^
ClearLogo::~ClearLogo()
{
}

//������
void ClearLogo::Initialize()
{
    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("ClearLogo.png");
    assert(hPict_ >= 0);
}

//�X�V
void ClearLogo::Update()
{
}

//�`��
void ClearLogo::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//�J��
void ClearLogo::Release()
{
}