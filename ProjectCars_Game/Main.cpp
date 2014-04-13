
#include "OpenGLRenderer.h"
#include "GameObjectFactory.h"
#include "GameMain.h"
#include "GameGUI.h"

int main()
{
	OpenGLRenderer* engine = new OpenGLRenderer();

	GameObjectFactory::CreateActor<GameMain>();

	GameGUI* gameGUI = (GameGUI*) GameObjectFactory::CreateActor<GameGUI>();


	engine->Start();
	return 0;
}