
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

	Vect2 GetDistanceFrom(Vect2 other)
	{
		return Vect2(abs(X - other.X), abs(Y - other.Y));
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

	Size(int _width, int _height)
	{
		width = _width;
		height = _height;
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
	Size size;
	Vect2 origin;

	Rect()
	{
		SetSize(0, 0);
		SetOrigin(0, 0);
	}

	Rect(int _width, int _height)
	{
		SetSize(_width, _height);
		SetOrigin(0, 0);
	}

	Rect(int _width, int _height, int _xOrigin, int _yOrigin)
	{
		SetSize(_width, _height);
		SetOrigin(_xOrigin, _yOrigin);
	}

	void SetSize(int _width, int _height)
	{
		size = Size(_width, _height);
	}

	void SetOrigin(int _xOrigin, int _yOrigin)
	{
		origin = Vect2(_xOrigin, _yOrigin);
	}

	Size GetSize() const
	{
		return size;
	}

	Vect2 GetOrigin() const
	{
		return origin;
	}
};

/*
	TODO: Make the function to return the converted position. (GLfloat* GameSpaceToOpenGLSpace(Vect2 gamePos))
	NOTE: I had problem using the returned array with SetUniformVect2 
*/

static void GameSpaceToOpenGLSpace(Vect2& gamePos, GLfloat glPos[2] )
{
	//Size windowSize = OpenGLRenderer::GetRenderer()->GetWindowSize();
	//TODO: wtf is this? refactor it.
	glPos[0] = (float(gamePos.X) / 800) - 1;
	glPos[1] = (float(gamePos.Y) / 600) - 1;
}

static bool AreIntersecting(const Rect& rect1, const Rect& rect2)
{
	Vect2 origin1 = rect1.GetOrigin();
	Vect2 origin2 = rect2.GetOrigin();
	Vect2 dist = origin1.GetDistanceFrom(origin2);

	int xtreshold = (rect1.GetSize().width + rect2.GetSize().width) / 2;
	int ytreshold = (rect1.GetSize().height + rect2.GetSize().height) / 2;

	return (dist.X < xtreshold && dist.Y < ytreshold);

}
