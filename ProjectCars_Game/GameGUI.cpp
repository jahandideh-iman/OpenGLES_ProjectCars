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
}

void GameGUI::Update(float dt)
{
	GameObject::Update(dt);
	scoreLabel->SetText(("Score 35"));
}
