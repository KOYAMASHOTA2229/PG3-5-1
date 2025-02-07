#include "StageScene.h"
#include <Novice.h>

// キー入力結果を受け取る箱
char keys[256] = { 0 };
char preKeys[256] = { 0 };

//機体の宣言
int playerPosX = 640;
int playerPosY = 600;
int playerR = 50;
int playerSpeedX = 10;
int playerSpeedY = 10;

//敵の宣言
int enemyPosX = 640;
int enemyPosY = 100;
int enemyR = 25;
int enemySpeedX = 5;

//敵が生きているフラグ
int isEnemyAlive = 1;
int distance = 0;

//弾の宣言
int bulletPosX = 640;
int bulletPosY = 360;
int bulletR = 15;
int bulletSpeedY = 10;

//弾を撃つフラグ
int isBulletShot = 1;

void StageScene::Iint()
{
}

void StageScene::Update()
{
	//弾フラグ
	if (isBulletShot == 0 && keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) { //弾が出ていなくて、SPACEキーを押したとき
		isBulletShot = true;  //フラグがTRUEになる(弾が出る)
		bulletPosX = playerPosX;
		bulletPosY = playerPosY;
	}


	distance = (enemyPosX - bulletPosX) * (enemyPosX - bulletPosX) + (enemyPosY - bulletPosY) * (enemyPosY - bulletPosY);
	if (isEnemyAlive == 1 && isBulletShot == 1) //敵が生きてて、弾が出てるとき
	{
		if ((enemyR + bulletR) * (enemyR + bulletR) >= distance) {//弾が当たれば
			isEnemyAlive = 0; //敵が消滅
			isBulletShot = 0; //弾消滅
		}
	}
}

void StageScene::Draw()
{
	//弾描画
	if (isBulletShot == 1)
	{
		Novice::DrawTriangle(bulletPosX, bulletPosY - bulletR, bulletPosX - bulletR, bulletPosY + bulletR, bulletPosX + bulletR, bulletPosY + bulletR, WHITE, kFillModeSolid);
	}
	//機体描画
	Novice::DrawEllipse(playerPosX, playerPosY, playerR, playerR, 0.0f, RED, kFillModeSolid);

	//敵描画
	if (isEnemyAlive == 1)
	{
		Novice::DrawEllipse(enemyPosX, enemyPosY, enemyR, enemyR, 0.0f, WHITE, kFillModeSolid);
	}
}
