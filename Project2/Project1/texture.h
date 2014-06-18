#pragma once
#include <string>
#include <GL\glew.h>


class Texture
{
public:
	Texture(const std::string& fileName);
	virtual ~Texture();

	void Bind(unsigned int unit);

private:
	Texture(const Texture& other){}
	void operator=(const Texture& other){}

	GLuint m_texture;
};

