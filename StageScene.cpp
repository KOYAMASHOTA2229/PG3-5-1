#include "StageScene.h"
#include <Novice.h>

// �L�[���͌��ʂ��󂯎�锠
char keys[256] = { 0 };
char preKeys[256] = { 0 };

//�@�̂̐錾
int playerPosX = 640;
int playerPosY = 600;
int playerR = 50;
int playerSpeedX = 10;
int playerSpeedY = 10;

//�G�̐錾
int enemyPosX = 640;
int enemyPosY = 100;
int enemyR = 25;
int enemySpeedX = 5;

//�G�������Ă���t���O
int isEnemyAlive = 1;
int distance = 0;

//�e�̐錾
int bulletPosX = 640;
int bulletPosY = 360;
int bulletR = 15;
int bulletSpeedY = 10;

//�e�����t���O
int isBulletShot = 1;

void StageScene::Iint()
{
}

void StageScene::Update()
{
	//�e�t���O
	if (isBulletShot == 0 && keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) { //�e���o�Ă��Ȃ��āASPACE�L�[���������Ƃ�
		isBulletShot = true;  //�t���O��TRUE�ɂȂ�(�e���o��)
		bulletPosX = playerPosX;
		bulletPosY = playerPosY;
	}


	distance = (enemyPosX - bulletPosX) * (enemyPosX - bulletPosX) + (enemyPosY - bulletPosY) * (enemyPosY - bulletPosY);
	if (isEnemyAlive == 1 && isBulletShot == 1) //�G�������ĂāA�e���o�Ă�Ƃ�
	{
		if ((enemyR + bulletR) * (enemyR + bulletR) >= distance) {//�e���������
			isEnemyAlive = 0; //�G������
			isBulletShot = 0; //�e����
		}
	}
}

void StageScene::Draw()
{
	//�e�`��
	if (isBulletShot == 1)
	{
		Novice::DrawTriangle(bulletPosX, bulletPosY - bulletR, bulletPosX - bulletR, bulletPosY + bulletR, bulletPosX + bulletR, bulletPosY + bulletR, WHITE, kFillModeSolid);
	}
	//�@�̕`��
	Novice::DrawEllipse(playerPosX, playerPosY, playerR, playerR, 0.0f, RED, kFillModeSolid);

	//�G�`��
	if (isEnemyAlive == 1)
	{
		Novice::DrawEllipse(enemyPosX, enemyPosY, enemyR, enemyR, 0.0f, WHITE, kFillModeSolid);
	}
}
