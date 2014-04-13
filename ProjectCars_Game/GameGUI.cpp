#include "GameGUI.h"


GameGUI::GameGUI() : GameObject()
{
}


GameGUI::~GameGUI()
{
}

void GameGUI::OnCreation()
{
	scoreLabel = GameObjectFactory::AddTextComponent(this, "Score ");
	scoreLabel->SetPosition(Vect2(50, 550));

	score = GameObjectFactory::AddTextComponent(this, "0");
	score->SetPosition(Vect2(150, 550));
}

void GameGUI::Update(float dt)
{
	GameObject::Update(dt);
	score->SetText(IntToText(gameMain->score));
}

void GameGUI::SetGame(GameMain* _game)
{
	gameMain = _game;
}