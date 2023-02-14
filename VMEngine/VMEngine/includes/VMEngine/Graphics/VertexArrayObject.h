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
	// x	//y		//z
	-0.5f,	-0.5f,	0.0f,	//bottom left - index 0
	 0.5f,	-0.5f,	0.0f,	//bottom right - index 1
	 0.5f,	 0.5f,	0.0f,	//top right - index 2
	-0.5f,	 0.5f,  0.0f   //top left - index 3
};

const IndicesMatrix CircleIndices
{
	0, 3, 1,	//Triangle 1
	3, 2, 1		//Triangle 2
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