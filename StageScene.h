#pragma once
#include "IScene.h"

class StageScene :public IScene
{
public:
	void Iint() override;
	void Update()override;
	void Draw()override;
};

