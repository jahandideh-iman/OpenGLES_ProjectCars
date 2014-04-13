#include "WorkInProgressGUI.h"
#include "GameObjectFactory.h"


WorkInProgressGUI::WorkInProgressGUI() : GameObject()
{
}


WorkInProgressGUI::~WorkInProgressGUI()
{
}

void WorkInProgressGUI::OnCreation()
{
	GameObjectFactory::AddTextComponent(this, "work in progress")->SetPosition(Vect2(320,550));
}