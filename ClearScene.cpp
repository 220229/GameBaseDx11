#include "ClearScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "ClearLogo.h"

//�R���X�g���N�^
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene")
{
}

//������
void ClearScene::Initialize()
{
	Instantiate<ClearLogo>(this);
}

//�X�V
void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

//�`��
void ClearScene::Draw()
{
}

//�J��
void ClearScene::Release()
{
}
