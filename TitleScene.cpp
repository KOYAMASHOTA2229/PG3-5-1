#include "TitleScene.h"
#include <Novice.h>

// キー入力結果を受け取る箱
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
