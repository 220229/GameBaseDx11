#include "GameoverScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "GameoverLogo.h"

//�R���X�g���N�^
GameoverScene::GameoverScene(GameObject* parent)
	: GameObject(parent, "GameoverScene"), pText(nullptr)
{
}

//������
void GameoverScene::Initialize()
{
	Instantiate<GameoverLogo>(this);

	pText = new Text;
	pText->Initialize();
}

//�X�V
void GameoverScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//�`��
void GameoverScene::Draw()
{
	pText->Draw(540, 540, "SPACE:RETRY");
}

//�J��
void GameoverScene::Release()
{
}