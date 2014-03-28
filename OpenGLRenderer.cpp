#include "OpenGLRenderer.h"

using namespace std;



GLuint OpenGLRenderer::programObject;
OpenGLRenderer* OpenGLRenderer::renderer = nullptr;


void DrawHelper(ESContext * contex)
{
	/* OpenGL doesn't suppert direct class method callBacks*/
	OpenGLRenderer::GetRenderer()->Render(contex);
}

void UpdateHelper(ESContext* contex, float dt)
{
	OpenGLRenderer::GetRenderer()->Update(contex,dt);
}

void HandleInputHelper(ESContext* context, unsigned char key, int X, int Y)
{
	OpenGLRenderer::GetRenderer()->HandleInput(context, key, X, Y);
}

OpenGLRenderer::OpenGLRenderer()
{
	if (renderer == nullptr)
	{
		renderer = this;
		Initialize();
	}
		
}


OpenGLRenderer::~OpenGLRenderer()
{
}

void OpenGLRenderer::Start()
{
	esMainLoop(esContext);
	Release();
	
}
void OpenGLRenderer::Initialize()
{
	inputHandler = new WindowsInputHandler();

	esContext = new ESContext();


	InitializeContext(esContext);

	esRegisterDrawFunc(esContext, DrawHelper);
	esRegisterUpdateFunc(esContext, UpdateHelper);

	//esRegisterKeyFunc(esContext, HandleInputHelper);	
}

void OpenGLRenderer::InitializeContext(ESContext * context)
{
	esInitContext(esContext);

	esCreateWindow(esContext, L"Drawing Primitives", 800, 600, ES_WINDOW_RGB);

	glViewport(0, 0, context->width, context->height);
	programObject = glCreateProgram();
	if (!programObject)
	{
		cout << "Could not load program object";
		Release();
		std::exit(0);
	}

	/*SpriteComponent *comp= new SpriteComponent(programObject);
	comp->Load();
	spriteComponents.push_back(comp);*/
}

void OpenGLRenderer::Render(ESContext* context)
{
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
	//At the beginning of each frame, clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < spriteComponents.size(); ++i)
		spriteComponents[i]->Render();

	eglSwapBuffers(context->eglDisplay, context->eglSurface);
}

void OpenGLRenderer::Update(ESContext* contex, float dt)
{
	inputHandler->Update(dt);
	for (int i = 0; i < gameObjects.size(); ++i)
		gameObjects[i]->Update(dt);
}

void OpenGLRenderer::HandleInput(ESContext* context, unsigned char key, int X, int Y)
{
	std::cout << "Input is " << key << " " << X << " " << Y << std::endl;
}

void OpenGLRenderer::Release()
{
	glDeleteProgram(programObject);
	for (int i = 0; i < spriteComponents.size(); ++i)
		spriteComponents[i]->Release();
}


GLuint OpenGLRenderer::GetProgramObject()
{
	return programObject;
}

OpenGLRenderer* OpenGLRenderer::GetRenderer()
{
	return renderer;
}


void OpenGLRenderer::AddGameObject(GameObject* obj)
{
	gameObjects.push_back(obj);
}

void  OpenGLRenderer::AddSpriteComponent(SpriteComponent* sprite)
{
	spriteComponents.push_back(sprite);
}

void OpenGLRenderer::AddCollisionComponent(CollisionComponent* collision)
{
	collisionComponents.push_back(collision);
}

void OpenGLRenderer::RegisterOnPressKey(GameObject* _obj, EInputKey _key, inputCallBack _callBack)
{
	inputHandler->RegisterOnPressKey(_obj, _key, _callBack);
}

void OpenGLRenderer::RegisterOnReleaseKey(GameObject* _obj,EInputKey _key, inputCallBack _callBack)
{
	inputHandler->RegisterOnReleaseKey(_obj, _key, _callBack);
}

Size OpenGLRenderer::GetWindowSize()
{
	Size size;

	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	size.width = viewport[2] - viewport[0];
	size.height = viewport[3] - viewport[1];

	return size;
}
