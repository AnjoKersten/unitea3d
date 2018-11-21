#ifndef RENDERER_H
#define RENDERER_H

#include <glad.h>
#include <glfw3.h>
#include <iostream>

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
	void DrawRectangle(Texture texture);

	void CreateTriangle();
	void DrawTriangle();

private:
	int _WIDTH = 800;
	int _HEIGHT = 600;

	void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	unsigned int VBO, VAO;
};

#endif