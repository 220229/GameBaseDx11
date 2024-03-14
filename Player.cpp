#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "BulletP.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Model\\Player.fbx");
    assert(hModel_ >= 0);
    transform_.position_.x = -10;
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
    AddCollider(collision);

}
float spowncooldown = 0;
//�X�V
void Player::Update()
{
    //W��������Ă�����
    if (Input::IsKey(DIK_W))
    {
        //���炩�̏���
        transform_.position_.y += 0.2;
    }
    //S��������Ă�����
    if (Input::IsKey(DIK_S))
    {
        //���炩�̏���
        transform_.position_.y -= 0.2;
    }

    if (Input::IsKeyDown(DIK_SPACE))
    {
        BulletP* p = Instantiate<BulletP>(this->GetParent());
        p->SetPosition(this->transform_.position_);//�v���C���[�̈ʒu
    }
    if (Input::IsKeyDown(DIK_SPACE))
    {
        BulletP* p = Instantiate<BulletP>(this->GetParent());
        p->SetPosition(this->transform_.position_);//�v���C���[�̈ʒu
    }
}

//�`��
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}