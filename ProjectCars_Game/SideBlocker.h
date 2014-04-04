#pragma once
#include "GameObject.h"
class SideBlocker :
	public GameObject
{
public:
	~SideBlocker();

	void OnCreation() override;

	void InitialBlocker(Size size);


};