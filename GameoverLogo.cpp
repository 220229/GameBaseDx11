#include "GameoverLogo.h"
#include "Engine/Image.h"

//�R���X�g���N�^
GameoverLogo::GameoverLogo(GameObject* parent)
    :GameObject(parent, "GameoverLogo"), hPict_(-1)
{
}

//�f�X�g���N�^
GameoverLogo::~GameoverLogo()
{
}

//������
void GameoverLogo::Initialize()
{
    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("GameoverLogo.png");
    assert(hPict_ >= 0);
}

//�X�V
void GameoverLogo::Update()
{
}

//�`��
void GameoverLogo::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//�J��
void GameoverLogo::Release()
{
}
