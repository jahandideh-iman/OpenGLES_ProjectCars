#pragma once
#include "GameObject.h"
class WorkInProgressGUI :
	public GameObject
{
public:
	WorkInProgressGUI();
	~WorkInProgressGUI();

	void OnCreation() override;
};

