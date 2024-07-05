#pragma once
#include "IScene.h"

class ClearScene :public IScene
{
public:
	void Iint() override;
	void Update()override;
	void Draw()override;
};

