#include "PlayScene.h"
#include "Engine/Camera.h"

#include "Player.h"
#include "Enemy.h"
#include "BulletP.h"

#include "Engine/Camera.h"
#include "Engine/Input.h"


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
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
}

void PlayScene::Update()
{
	
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
