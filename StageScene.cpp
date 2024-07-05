#include "StageScene.h"
#include <Novice.h>

// ÉLÅ[ì¸óÕåãâ ÇéÛÇØéÊÇÈî†
char keys[256] = { 0 };
char preKeys[256] = { 0 };

//ã@ëÃÇÃêÈåæ
int playerPosX = 640;
int playerPosY = 600;
int playerR = 50;
int playerSpeedX = 10;
int playerSpeedY = 10;

//ìGÇÃêÈåæ
int enemyPosX = 640;
int enemyPosY = 100;
int enemyR = 25;
int enemySpeedX = 5;

//ìGÇ™ê∂Ç´ÇƒÇ¢ÇÈÉtÉâÉO
int isEnemyAlive = 1;
int distance = 0;

//íeÇÃêÈåæ
int bulletPosX = 640;
int bulletPosY = 360;
int bulletR = 15;
int bulletSpeedY = 10;

//íeÇåÇÇ¬ÉtÉâÉO
int isBulletShot = 1;

void StageScene::Iint()
{
}

void StageScene::Update()
{
	//íeÉtÉâÉO
	if (isBulletShot == 0 && keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) { //íeÇ™èoÇƒÇ¢Ç»Ç≠ÇƒÅASPACEÉLÅ[ÇâüÇµÇΩÇ∆Ç´
		isBulletShot = true;  //ÉtÉâÉOÇ™TRUEÇ…Ç»ÇÈ(íeÇ™èoÇÈ)
		bulletPosX = playerPosX;
		bulletPosY = playerPosY;
	}


	distance = (enemyPosX - bulletPosX) * (enemyPosX - bulletPosX) + (enemyPosY - bulletPosY) * (enemyPosY - bulletPosY);
	if (isEnemyAlive == 1 && isBulletShot == 1) //ìGÇ™ê∂Ç´ÇƒÇƒÅAíeÇ™èoÇƒÇÈÇ∆Ç´
	{
		if ((enemyR + bulletR) * (enemyR + bulletR) >= distance) {//íeÇ™ìñÇΩÇÍÇŒ
			isEnemyAlive = 0; //ìGÇ™è¡ñ≈
			isBulletShot = 0; //íeè¡ñ≈
		}
	}
}

void StageScene::Draw()
{
	//íeï`âÊ
	if (isBulletShot == 1)
	{
		Novice::DrawTriangle(bulletPosX, bulletPosY - bulletR, bulletPosX - bulletR, bulletPosY + bulletR, bulletPosX + bulletR, bulletPosY + bulletR, WHITE, kFillModeSolid);
	}
	//ã@ëÃï`âÊ
	Novice::DrawEllipse(playerPosX, playerPosY, playerR, playerR, 0.0f, RED, kFillModeSolid);

	//ìGï`âÊ
	if (isEnemyAlive == 1)
	{
		Novice::DrawEllipse(enemyPosX, enemyPosY, enemyR, enemyR, 0.0f, WHITE, kFillModeSolid);
	}
}
