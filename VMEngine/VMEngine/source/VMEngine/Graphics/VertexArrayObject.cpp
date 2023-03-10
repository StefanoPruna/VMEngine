#include "VMEngine/Graphics/VertexArrayObject.h"
#include "GLEW/glew.h"

//Constructors - to define and initialise objects from the header
VertexArrayObject::VertexArrayObject()
{
	ID = EAB = VAB = 0;

	/*Shape.PositionMatrix = TrianglePositions;
	Shape.IndecesMatrix = TriangleIndices;*/
	/*Shape.PositionMatrix = PolyPositions;
	Shape.IndecesMatrix = PolyIndices;*/
	Shape.PositionMatrix = CirclePositions;
	Shape.IndecesMatrix = CircleIndices;

	// Handle the positions Matrix
	//Create the ID for the VAO
	glGenVertexArrays(1, &ID);

	//bind the data to this vertex array
	glBindVertexArray(ID);

	//Create an ID for the array buffer
	glGenBuffers(1, &VAB);
	//Bind the above IDs to the OpenGL
	glBindBuffer(GL_ARRAY_BUFFER, VAB);
	//Run through the data and attach the vertices to the VAB
	glBufferData(GL_ARRAY_BUFFER, 
		Shape.PositionMatrix.size() * sizeof(float), 
		&Shape.PositionMatrix[0],
		GL_STATIC_DRAW);

	//Handle the Indices
	//Create an ID for the element array buffer
	glGenBuffers(1, &EAB);
	//Bind the above ID to the OpenGl as the element buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EAB);
	//Run through the data and attach the inidices to the EAB
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		Shape.IndecesMatrix.size() * sizeof(vmuint),
		&Shape.IndecesMatrix[0],
		GL_STATIC_DRAW);

	//Assign the vertices and indices to the VAO
	glVertexAttribPointer(
		0,					//data set - 0 = the first data set in the array
		3,					//How many vertices/numbers in our matrix we need to make a triangle
		GL_FLOAT, GL_FALSE, //data type, whether we normalise the values
		sizeof(float) * 3,  //stride - the length it takes to get to each number
		(void*)0			//override to 0, the offset of how many number to skip in the matrix
	);

	// enable the vertex array
	glEnableVertexAttribArray(0);

	//Clear the buffer
	glBindVertexArray(0);
}

VertexArrayObject::~VertexArrayObject()
{
	//Clean the VAO in OpenGL
	glDeleteVertexArrays(1, &ID);

	//Clean the vectors
	Shape.PositionMatrix.clear();
	Shape.IndecesMatrix.clear();

	cout << "Deleted VAO..." << "\n";
}

void VertexArrayObject::Draw()
{
	//bind our VAO to the current buffer
	glBindVertexArray(ID);
	//Draw the 3D object/VAO
	glDrawElements(GL_TRIANGLES,		//What type of object we are drawing 
		Shape.IndecesMatrix.size(),		//How many vertices do we draw
		GL_UNSIGNED_INT,				//What type of data that is being input
		(void*)0);						//How many we should skip

	//Clear the VAO from the current array to allow for the next object
	glBindVertexArray(0);
}
