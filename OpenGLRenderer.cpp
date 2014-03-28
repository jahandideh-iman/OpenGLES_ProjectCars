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

}

void OpenGLRenderer::InitializeContext(ESContext * context)
{
	esInitContext(esContext);

	esCreateWindow(esContext, L"Project Cars", 800, 600, ES_WINDOW_RGB);

	glViewport(0, 0, context->width, context->height);
	programObject = glCreateProgram();
	if (!programObject)
	{
		cout << "Could not load program object";
		Release();
		std::exit(0);
	}
}

void OpenGLRenderer::Render(ESContext* context)
{
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
	//At the beginning of each frame, clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < renderableComponents.size(); ++i)
		renderableComponents[i]->Render();


	eglSwapBuffers(context->eglDisplay, context->eglSurface);
}

void OpenGLRenderer::Update(ESContext* contex, float dt)
{
	inputHandler->Update(dt);
	for (int i = 0; i < gameObjects.size(); ++i)
		gameObjects[i]->Update(dt);

	CheckCollisions();
}


void OpenGLRenderer::Release()
{
	glDeleteProgram(programObject);
	for (int i = 0; i < renderableComponents.size(); ++i)
		renderableComponents[i]->Release();
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

void  OpenGLRenderer::AddRenderableComponent(RenderableComponent* comp)
{
	renderableComponents.push_back(comp);
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

void OpenGLRenderer::CheckCollisions()
{
	for (int i = 0; i < collisionComponents.size() ; ++i)
	{
		for (int j = i + 1; j < collisionComponents.size(); ++j)
		{
			CheckCollision(collisionComponents[i], collisionComponents[j]);
		}
	}

}

void OpenGLRenderer::CheckCollision(CollisionComponent* col1, CollisionComponent* col2)
{
	
	if (AreIntersecting(col1->GetBoundingRect(), col2->GetBoundingRect()))
	{
		std::cout << "Collision" << endl;
		GameObject* owner1 = col1->GetOwner();
		GameObject* owner2 = col2->GetOwner();

		owner1->OnCollision(owner2);
		owner2->OnCollision(owner1);

		if (col1->GetPhysicsType() == Phys_Blocking
			&& col2->GetPhysicsType() == Phys_Blocking)
		{
			Vect2 owner1NewPos = owner1->GetPosition();
		}
	}
}
