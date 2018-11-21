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
	
	Texture sampleTex;
	sampleTex.SetPath("assets/brickTex.jpg");

	
	renderer.CreateRectangle();
	//renderer.CreateTriangle();
	

	while (!glfwWindowShouldClose(renderer.window))
	{
		
		renderer.processInput(renderer.window);

		demoShader.use();

		renderer.DrawRectangle(sampleTex);
		//renderer.DrawTriangle();
		
		glfwSwapBuffers(renderer.window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}
