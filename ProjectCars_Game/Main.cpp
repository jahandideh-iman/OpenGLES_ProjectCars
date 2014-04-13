
#include "OpenGLRenderer.h"
#include "GameObjectFactory.h"
#include "GameMain.h"
#include "GameGUI.h"

int main()
{
	OpenGLRenderer* engine = new OpenGLRenderer();

	GameMain* gameMain =(GameMain*) GameObjectFactory::CreateActor<GameMain>();

	GameGUI* gameGUI = (GameGUI*) GameObjectFactory::CreateActor<GameGUI>();
	gameGUI->SetGame(gameMain);


	engine->Start();
	return 0;
}