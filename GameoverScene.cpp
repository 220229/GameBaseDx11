#include "GameoverScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "GameoverLogo.h"

//コンストラクタ
GameoverScene::GameoverScene(GameObject* parent)
	: GameObject(parent, "GameoverScene"), pText(nullptr)
{
}

//初期化
void GameoverScene::Initialize()
{
	Instantiate<GameoverLogo>(this);

	pText = new Text;
	pText->Initialize();
}

//更新
void GameoverScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void GameoverScene::Draw()
{
	pText->Draw(540, 540, "SPACE:RETRY");
}

//開放
void GameoverScene::Release()
{
}