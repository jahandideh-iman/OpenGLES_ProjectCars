#pragma once
#include "RenderableComponent.h"
#include "Utilities.h"


class DebugRectangleComponent :
	public RenderableComponent
{
public:
	DebugRectangleComponent( Rect rect);
	~DebugRectangleComponent();

	bool Load(Size size);

	void Render() override;


	OpenGLKey GetKey() override;



private:
	Rect boundingRect;
	GLfloat color[4]; 
};

