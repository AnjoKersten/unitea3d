#ifndef RENDERER_H
#define RENDERER_H

#include <glad.h>
#include <glfw3.h>
#include <iostream>

#include "src/u3dconfig.h"
#include "src/stb_image.h"
#include "src/shader.h"
#include "src/texture.h"

class Renderer
{
public:
	Renderer();
	virtual ~Renderer();
	GLFWwindow* window;

	void processInput(GLFWwindow* window);

	void CreateRectangle();
	void DrawRectangle();

	void CreateTriangle();
	void DrawTriangle();

private:

	

	unsigned int VBO, VAO, EBO;
};

#endif