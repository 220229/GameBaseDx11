#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class TitleLogo : public GameObject
{
    int hPict_;    //�摜�ԍ�
public:
    //�R���X�g���N�^
    TitleLogo(GameObject* parent);

    //�f�X�g���N�^
    ~TitleLogo();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};