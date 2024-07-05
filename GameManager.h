#pragma once

#include<memory>
#include"IScene.h"
#include"StageScene.h"
#include"TitleScene.h"
#include"ClearScene.h"

class GameManager
{
private:

	std::unique_ptr<IScene>sceneArr_[3];

	int currentSceneNo_ = 0;
	int prevSceneNo_ = 0;

public:
	GameManager();
	~GameManager();

	int Run();
};

