#pragma once
#include <Windows.h>

class Game;

class Scene
{
public:
	Scene();
	~Scene();

	virtual void Render(Game* _game) = 0;
	virtual void Update(Game* _game = 0) = 0;
	virtual void Initialize() = 0;

};