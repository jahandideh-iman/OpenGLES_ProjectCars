#include "DebugRectangleComponent.h"

using namespace std;

DebugRectangleComponent::DebugRectangleComponent(Rect rect)
:RenderableComponent() 
{
	boundingRect = rect;
	color[0] = 0;
	color[1] = 0;
	color[2] = 1;
	color[3] = 1;
}


DebugRectangleComponent::~DebugRectangleComponent()
{
}

bool DebugRectangleComponent::Load(Size size)
{
	//When we defined a variable as an a
	auto hr = this->vShader->LoadFromFile(
		GL_VERTEX_SHADER,
		"Assets/Rect_VShader.txt");
	if (!hr)
	{
		cout << "Error on loading vertex shader" << endl;
		return hr;
	}

	//the fragment shader returns the color of pixel
	hr = this->fShader->LoadFromFile(GL_FRAGMENT_SHADER,
		"Assets/Rect_FShader.txt");
	if (!hr)
	{
		cout << "Error on loading fragment shader" << endl;
		return hr;
	}

	//Bind the first index to the "aPosition"
	this->vShader->Bind(0, "aPosition");
	//Link the shader
	this->vShader->Link();

	const int vSize = 12;
	auto vertices = unique_ptr<GLfloat[]>(new GLfloat[vSize]
	{
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			-0.5f, 0.5f, 0.0f,
			0.5f, 0.5f, 0.0f,
	});

	vertices.get()[0] = -(size.width ) / 800.0;
	vertices[1] = -(size.height ) / 600.0;
	vertices[2] = 0;
	vertices[3] = (size.width) / 800.0;
	vertices[4] = -(size.height) / 600.0;
	vertices[5] = 0;
	vertices[6] = -(size.width ) / 800.0;
	vertices[7] = (size.height ) / 600.0;
	vertices[8] = 0;
	vertices[9] = (size.width) / 800.0;
	vertices[10] = (size.height ) / 600.0;
	vertices[11] = 0;

	//Generate a single buffer and get the pointer to this buffer
	glGenBuffers(1, &vertexBuffer);
	//Specify that we need a vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	/*
	Set the data of vertex buffer
	GL_STATIC_DRAW means, the buffer object data will be specified once by the application and used many times to draw primitives.
	GL_DYNAMIC_DRAW means, the buffer object data will be specified repeatedly by the application and used many times to draw primitives
	GL_STREAM_DRAW means, the buffer object data will be specified once by the application and used a few times to draw primitives
	*/
	glBufferData(
		GL_ARRAY_BUFFER,
		vSize * sizeof(GLfloat),
		vertices.get(),
		GL_STATIC_DRAW);


	//Now let's define our index buffer
	this->indexBufferSize = 6;
	auto indices = unique_ptr<GLushort[]>(new GLushort[this->indexBufferSize]
	{
		0, 1, 2, 2, 1, 3
	});
	//Same as before first generate a single index buffer and get the pointer to this buffer
	glGenBuffers(1, &indexBuffer);
	//Define this buffer as index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	//Set the data of index buffer
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		this->indexBufferSize * sizeof(GLushort),
		indices.get(),
		GL_STATIC_DRAW);

	//Release our local arrays
	indices.release();
	vertices.release();

	return hr;
}

void DebugRectangleComponent::Render()
{

	//Draw the triangle using vertices
	glUseProgram(programObject);

	//TODO: find a better soloution ( not reseting it every frame)
	GLfloat pos[2];
	GameSpaceToOpenGLSpace(GetPosition(), pos);
	this->vShader->SetUniformVect2("uPosition", pos);

	this->vShader->SetUniformVect4("uColor", color);

	//Bind to the vertex buffer and enable the vertex attribute array, that is only "aPosition"
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//Bind to the index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	// Draw the triangles
	glDrawElements(
		GL_TRIANGLES,// mode
		this->indexBufferSize,// count of indices
		GL_UNSIGNED_SHORT,// type of index buffer
		0// offset of index buffer
		);

	//Disable the vertex attribute array
	glDisableVertexAttribArray(0);
}


OpenGLKey DebugRectangleComponent::GetKey()
{
	return "OpenGL_DebugRec";
}