#include "pch.h"
#include "SpriteComponent.h"


using namespace std;

SpriteComponent::SpriteComponent() 
: RenderableComponent()
{
}

SpriteComponent::~SpriteComponent()
{
}

bool SpriteComponent::Load(char* spritePath)
{
	//When we defined a variable as an a
	this->programObject = programObject;
	auto hr = this->vShader->LoadFromFile(
		GL_VERTEX_SHADER,
		"Assets/Sprite_VShader.txt");
	if (!hr)
	{
		cout << "Error on loading vertex shader" << endl;
		return hr;
	}

	//the fragment shader returns the color of pixel
	hr = this->fShader->LoadFromFile(
		GL_FRAGMENT_SHADER,
		"Assets/Sprite_FShader.txt");
	if (!hr)
	{
		cout << "Error on loading fragment shader" << endl;
		return hr;
	}

	//Bind the first index to the "aPosition"
	this->vShader->Bind(0, "aPosition");
	//Link the shader
	this->vShader->Link();

	this->vertexBufferSize = 20;
	auto vertices = unique_ptr<GLfloat[]>(new GLfloat[this->vertexBufferSize]
	{
		-0.5f, -0.5f, 0.0f,	//Position0
			0.0f, 0.0f,       //TexCoord0 
			0.5f, -0.5f, 0.0f,	//Position1
			1.0f, 0.0f,        //TexCoord1
			-0.5f, 0.5f, 0.0f,	//Position2
			0.0f, 1.0f,         //TexCoord2
			0.5f, 0.5f, 0.0f,	//Position3
			1.0f, 1.0f         //TexCoord3
	});
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
		this->vertexBufferSize * sizeof(GLfloat),
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
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indexBufferSize * sizeof(GLushort), indices.get(), GL_STATIC_DRAW);

	//Release our local arrays
	indices.release();
	vertices.release();

	auto texture2D = unique_ptr<Texture2D>(new Texture2D());

	//Create a texture or load from the assets
	//this->texture2DObj = texture2D->CreateTexture2D();
	this->texture2DObj = texture2D->LoadTexture(spritePath);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->texture2DObj);

	// Set the sampler texture unit to 0
	glUniform1i(1, 0);
	// Wrap texture coordinates by repeating
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	return hr;
}

void SpriteComponent::Render()
{
	//Draw the triangle using vertices
	glUseProgram(programObject);
	//TODO: find a better soloution ( not reseting it every frame)
	GLfloat pos[2];;
	GameSpaceToOpenGLSpace(GetPosition(), pos);
	this->vShader->SetUniformVect2("uPosition",pos);

	

	//Bind to the vertex buffer and enable the vertex attribute array, that is only "aPosition"
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	int offset = 0;
	//aPosition
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		this->vertexBufferSize,
		(const void *)offset);

	offset += 3 * sizeof(GLfloat);
	//aTextcoord
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1,
		2,
		GL_FLOAT,
		GL_FALSE,
		this->vertexBufferSize,
		(const void *)offset);

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
	glDisableVertexAttribArray(1);


}

//void SpriteComponent::SetPosition(Vect2 pos)
//{
//
//
//	GLfloat glPos[2];
//	
//
//	glPos[0] = 0.2;
//	glPos[1] = -0.2;
//	
//}

void SpriteComponent::Release()
{
	RenderableComponent::Release();
	this->texture2DObj = 0;
}

OpenGLKey SpriteComponent::GetKey()
{
	return "OpenGL_Sprite";
}