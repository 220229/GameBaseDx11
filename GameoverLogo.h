#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class GameoverLogo : public GameObject
{
    int hPict_;    //�摜�ԍ�
public:
    //�R���X�g���N�^
    GameoverLogo(GameObject* parent);

    //�f�X�g���N�^
    ~GameoverLogo();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};