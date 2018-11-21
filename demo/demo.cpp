#include <iostream>
#include <glad.h>
#include <glfw3.h>
#include "src/renderer.h"
#include "src/shader.h"
#include "src/stb_image.h"



int main()
{
	Renderer renderer;
	Shader demoShader("../src/shaders/sample.vs", "../src/shaders/sample.fs");

	int width, height, nrChannels;
	unsigned char *data = stbi_load("brickTex.jpg", &width, &height, &nrChannels, 0);

	renderer.CreateTriangle();

	while (!glfwWindowShouldClose(renderer.window))
	{
		
		renderer.processInput(renderer.window);

		demoShader.use();
		renderer.DrawTriangle();
		
		glfwSwapBuffers(renderer.window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}
