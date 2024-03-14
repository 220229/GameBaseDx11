#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "BulletP.h"
#include "Engine/SphereCollider.h"
#include "BulletE.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"

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
    transform_.position_.x = -13;
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
    AddCollider(collision);

}

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
    if (transform_.position_.y < -15.0)
    {
        transform_.position_.y = -15;
    }
    if (transform_.position_.y > 15.0)
    {
        transform_.position_.y = 15;
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

//�����ɓ�������
void Player::OnCollision(GameObject* pTarget)
{
    //���������Ƃ��̏���
    //�e�ɓ��������Ƃ�
    if (pTarget->GetObjectName() == "BulletE")
    {
        this->KillMe();
        pTarget->KillMe();
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
    }
}