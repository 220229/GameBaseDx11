#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class ClearLogo : public GameObject
{
    int hPict_;    //�摜�ԍ�
public:
    //�R���X�g���N�^
    ClearLogo(GameObject* parent);

    //�f�X�g���N�^
    ~ClearLogo();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};