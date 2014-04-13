#pragma once
#include "GameObject.h"
#include "TextComponent_BullShit.h"
#include "GameMain.h"

class GameGUI :
	public GameObject
{
public:
	GameGUI();
	~GameGUI();

	void OnCreation() override;
	void Update(float dt) override;

	void SetGame(GameMain* _game);

private:
	TextComponent_BullShit* scoreLabel;
	TextComponent_BullShit* score;
	GameMain* gameMain = nullptr;
};

