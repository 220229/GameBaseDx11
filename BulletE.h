#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class BulletE : public GameObject
{
    int hModel_;    //���f���ԍ�
public:
    //�R���X�g���N�^
    BulletE(GameObject* parent);

    //�f�X�g���N�^
    ~BulletE();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;
};