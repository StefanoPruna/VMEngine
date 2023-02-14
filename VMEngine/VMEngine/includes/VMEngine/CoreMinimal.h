#pragma once
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int vmuint;

//class dependency to GraphicsEngine class
class GraphicsEngine;

//Shared pointers will delete by themselves after use
//typedef to assigned a name to anything
typedef shared_ptr<GraphicsEngine> GraphicsEnginePtr;

class VertexArrayObject;
typedef VertexArrayObject VAO;
typedef shared_ptr<VAO> VAOPtr;
typedef vector<VAOPtr> VAOStack;

//For shape data and VAOs Matrices
typedef vector<float> PositionMatrix;
typedef vector<vmuint> IndicesMatrix;

struct ShapeData
{
	vector<float> PositionMatrix;
	vector<vmuint> IndecesMatrix;
};