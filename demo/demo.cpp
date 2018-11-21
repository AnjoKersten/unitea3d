#include <iostream>
#include <glad.h>
#include <glfw3.h>
#include "src/renderer.h"
#include "src/shader.h"



int main()
{
	Renderer renderer;
	Shader demoShader("../src/shaders/sample.vs", "../src/shaders/sample.fs");

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
