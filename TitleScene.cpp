#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "TitleLogo.h"

//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), pText(nullptr)
{
}

//初期化
void TitleScene::Initialize()
{
	Instantiate<TitleLogo>(this);

	pText = new Text;
	pText->Initialize();
}

//更新
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TitleScene::Draw()
{
	pText->Draw(540, 540, "SPACE:START");
}

//開放
void TitleScene::Release()
{
}