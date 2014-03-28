#pragma once
#include "RenderableComponent.h"
#include "Utilities.h"


class DebugRectangleComponent :
	public RenderableComponent
{
public:
	DebugRectangleComponent(GLuint programObj, Rect rect);
	~DebugRectangleComponent();

	bool Load(Size size);

	void Render() override;



private:
	Rect boundingRect;
	GLfloat color[4]; 
};

