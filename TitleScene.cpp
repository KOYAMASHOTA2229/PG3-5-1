#include "TitleScene.h"
#include <Novice.h>

// �L�[���͌��ʂ��󂯎�锠
char keys[256] = { 0 };
char preKeys[256] = { 0 };

void TitleScene::Iint()
{
}

void TitleScene::Update()
{
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
}
