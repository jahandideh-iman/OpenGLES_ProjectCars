
#pragma once

struct Vect2
{
	int X, Y;

	Vect2()
	{
		X = 0; 
		Y = 0; 
	}

	Vect2(int _x, int _y)
	{
		X = _x;
		Y = _y;
	}

	Vect2& operator=(const Vect2& other) // copy assignment
	{
		if (this != &other) 
		{ 
			this->X = other.X;
			this->Y = other.Y;
		}
		return *this;
	}

	Vect2 operator+(const Vect2& other)
	{
		return Vect2(X+other.X , Y+other.Y);
	}

	Vect2 operator*(const float a)
	{
		return Vect2(X*a, Y*a);
	}
};

struct Size
{
	int width, height;

	Size()
	{
		width = 0;
		height = 0;
	}

	Size& operator=(const Size& other) // copy assignment
	{
		if (this != &other)
		{
			this->width = other.width;
			this->height = other.height;
		}
		return *this;
	}
};

struct Rect
{
	int width, height;

	Rect()
	{
		width = 0;
		height = 0;
	}

	Rect(int _width, int _height)
	{
		width = _width;
		height = _height;
	}
};

/*
	TODO: Make the function to return the converted position. (GLfloat* GameSpaceToOpenGLSpace(Vect2 gamePos))
	NOTE: I had problem using the returned array with SetUniformVect2 
*/

static void GameSpaceToOpenGLSpace(Vect2 gamePos, GLfloat glPos[2] )
{
	//Size windowSize = OpenGLRenderer::GetRenderer()->GetWindowSize();
	//TODO: wtf is this? refactor it.
	glPos[0] = (float(gamePos.X) / 800) - 0.5;
	glPos[1] = (float(gamePos.Y) / 600) - 0.5;
}
