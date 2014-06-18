#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>
#include "vertex.h"

class Mesh
{
public:

	Mesh(Vertex* verticies, unsigned int numVerticies);
	virtual ~Mesh();
	void Draw();
private:
	Mesh(const Mesh& other){}
	void operator=(const Mesh& other){}

	enum
	{
		POSITION_VB,

		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};

