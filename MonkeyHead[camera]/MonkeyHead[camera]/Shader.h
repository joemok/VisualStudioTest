#pragma once
#include <string>
#include<GL/glew.h>
#include "Transform.h"
#include"Camera.h"

class Shader
{
public:
	Shader(const std::string& fileName);
	void Bind();//bind the shader, set the GPU in a state using vertex shader and frag shader in this class
	void Update(const Transform& transform, const Camera& camera);

	~Shader();
private:
	static const unsigned int NUM_SHADERS = 2;

	std::string LoadShader(const std::string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const std::string& text, GLenum shaderType);

	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
	
};

