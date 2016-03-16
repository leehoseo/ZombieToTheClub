#pragma once
#include <Windows.h>

class Scene
{
public:
	Scene();
	~Scene();

	virtual void Render() = 0;
	virtual void Update() = 0;


	virtual void Initialize() = 0;
};