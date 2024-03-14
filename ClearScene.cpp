#include "ClearScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "ClearLogo.h"

//�R���X�g���N�^
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene"), pText(nullptr)
{
}

//������
void ClearScene::Initialize()
{
	Instantiate<ClearLogo>(this);

	pText = new Text;
	pText->Initialize();
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
	pText->Draw(540, 540, "SPACE:TITLE");
}

//�J��
void ClearScene::Release()
{
}
