#include "TitleLogo.h"
#include "Engine/Image.h"

//�R���X�g���N�^
TitleLogo::TitleLogo(GameObject* parent)
    :GameObject(parent, "TitleLogo"), hPict_(-1)
{
}

//�f�X�g���N�^
TitleLogo::~TitleLogo()
{
}

//������
void TitleLogo::Initialize()
{
    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("TitleLogo.png");
    assert(hPict_ >= 0);
}

//�X�V
void TitleLogo::Update()
{
}

//�`��
void TitleLogo::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//�J��
void TitleLogo::Release()
{
}