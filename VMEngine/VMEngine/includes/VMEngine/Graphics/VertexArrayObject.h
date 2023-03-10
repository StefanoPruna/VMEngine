#pragma once
#include "VMEngine/CoreMinimal.h"

const PositionMatrix TrianglePositions
{
	// x	//y		//z
	-0.5f,	-0.5f,	0.0f,	//bottom left
	 0.5f,	-0.5f,	0.0f,	//bottom right
	 0.0f,	 0.5f,	0.0f	//top
};

const IndicesMatrix TriangleIndices
{
	0, 1, 2
};

const PositionMatrix PolyPositions
{
	// x	//y		//z
	-0.5f,	-0.5f,	0.0f,	//bottom left - index 0
	 0.5f,	-0.5f,	0.0f,	//bottom right - index 1
	 0.5f,	 0.5f,	0.0f,	//top right - index 2
	-0.5f,	 0.5f,  0.0f   //top left - index 3
};

const IndicesMatrix PolyIndices
{
	0, 3, 1,	//Triangle 1
	3, 2, 1		//Triangle 2
};

const PositionMatrix CirclePositions
{
	// x	 //y	  //z
    0.0f,    0.0f,	 0.0f,	 //bottom left - index 0
  -0.25f,   -0.5f,	 0.0f,	 //bottom right - index 1
   0.25f,   -0.5f,	 0.0f,	 //top right - index 2
	0.5f,  -0.25f,   0.0f,   //top left - index 3
    0.5f,	0.25f,   0.0f,   //left - index 4
   0.25f,    0.5f,   0.0f,	 //top - index 5
  -0.25f,    0.5f,   0.0f,   //right - index 6
   -0.5f,	0.25f,	 0.0f,	 //bottom - index 7
   -0.5f,  -0.25f,   0.0f    //index 8
};

const IndicesMatrix CircleIndices
{
	0, 1, 2,	//Triangle 1
	0, 2, 3,	//Triangle 2
	0, 3, 4,	//Triangle 3
	0, 4, 5,	//Triangle 4
	0, 5, 6,    //Triangle 5
	0, 6, 7,    //Triangle 6
	0, 7, 8,	//Triangle 7
	0, 8, 1		//Triangle 8
};

class VertexArrayObject
{
public:
	VertexArrayObject();
	~VertexArrayObject();

	void Draw();

private:
	ShapeData Shape;

	//This is unsigned int named vmuint from CoreMinimal.h
	// 
	//ID FOR THE VAO
	//VAB ID FOR THE VERTICES
	//EAB ID FOR THE INDICES
	vmuint ID, VAB, EAB;
};