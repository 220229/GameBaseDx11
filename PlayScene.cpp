#include "PlayScene.h"
#include "Engine/Camera.h"

#include "Player.h"
#include "Enemy.h"
#include "BulletP.h"

#include "Engine/Camera.h"
#include "Engine/Input.h"


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), pText(nullptr)
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	//Instantiate<BulletP>(this);


	Instantiate<Enemy>(this);
	
	for (int i = 0; i < 6; i++) {
		Instantiate<Enemy>(this);
	}

	Camera::SetPosition(XMFLOAT3(0, 0, -40));
	Camera::SetTarget(XMFLOAT3(0, 0, 0));

	pText = new Text;
	pText->Initialize();
}

void PlayScene::Update()
{
	
}

void PlayScene::Draw()
{
	pText->Draw(30, 30, "    W:UP");
	pText->Draw(30, 60, "    S:DOWN");
	pText->Draw(30, 90, "SPACE:SHOT");

}

void PlayScene::Release()
{
}
