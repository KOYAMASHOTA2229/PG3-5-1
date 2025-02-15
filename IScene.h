#pragma once

enum SCENE { TITLE, STAGE, CLEAR };

class IScene
{
protected:

	static int sceneNo;

public:

	virtual void Iint() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();

	int GetSceneNo();
};

