#pragma once
#include "GameObject.h"
#include "TextComponent_BullShit.h"
class GameGUI :
	public GameObject
{
public:
	GameGUI();
	~GameGUI();

	void OnCreation() override;
	void Update(float dt) override;

private:
	TextComponent_BullShit* scoreLabel;
};

