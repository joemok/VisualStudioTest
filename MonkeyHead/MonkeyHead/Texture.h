#pragma once
#include <string>
#include <GL/glew.h>

class Texture
{
public:
	Texture(const std::string& fileName);

	void Bind(unsigned int unit); // unit is the index of textures, there can be 0-31 kinds



	~Texture();


private:
	GLuint m_texture;
	
	 
};

