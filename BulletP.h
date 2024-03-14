#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class BulletP : public GameObject
{
    int hModel_;    //���f���ԍ�
public:
    //�R���X�g���N�^
    BulletP(GameObject* parent);

    //�f�X�g���N�^
    ~BulletP();

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