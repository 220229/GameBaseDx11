#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "TitleLogo.h"

//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), pText(nullptr)
{
}

//������
void TitleScene::Initialize()
{
	Instantiate<TitleLogo>(this);

	pText = new Text;
	pText->Initialize();
}

//�X�V
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//�`��
void TitleScene::Draw()
{
	pText->Draw(540, 540, "SPACE:START");
}

//�J��
void TitleScene::Release()
{
}