#include "ClearScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "ClearLogo.h"

//コンストラクタ
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene"), pText(nullptr)
{
}

//初期化
void ClearScene::Initialize()
{
	Instantiate<ClearLogo>(this);

	pText = new Text;
	pText->Initialize();
}

//更新
void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

//描画
void ClearScene::Draw()
{
	pText->Draw(540, 540, "SPACE:TITLE");
}

//開放
void ClearScene::Release()
{
}
