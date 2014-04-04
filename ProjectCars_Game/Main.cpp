
#include "OpenGLRenderer.h"
#include "GameObjectFactory.h"
#include "GameMain.h"

int main()
{
	OpenGLRenderer* engine = new OpenGLRenderer();

	GameObjectFactory::CreateActor<GameMain>();


	engine->Start();
	return 0;
}