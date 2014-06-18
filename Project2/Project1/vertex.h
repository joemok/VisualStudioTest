#pragma once
#include <glm\glm.hpp>

class Vertex
{
public:
	Vertex(const glm::vec3 pos)
	{
		this->pos = pos;
	}
	virtual ~Vertex() {}
private:
	glm::vec3 pos;
};

