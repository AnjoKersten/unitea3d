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
	
	
	renderer.CreateRectangle();
	//renderer.CreateTriangle();


	// Texture 1
	Texture sampleTex("assets/container.png");

	// Texture 2
	Texture awesomeFace("assets/awesomeface.png");
	
	demoShader.use();
	glUniform1i(glGetUniformLocation(demoShader.ID, "texture1"), 0);
	demoShader.setInt("texture2", 1);

	

	while (!glfwWindowShouldClose(renderer.window))
	{
		
		
		renderer.processInput(renderer.window);

		demoShader.use();

		//sampleTex.UpdateTexture();
		//awesomeFace.UpdateTexture();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, sampleTex.textureid);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, awesomeFace.textureid);

		renderer.DrawRectangle();
		renderer.DrawRectangle();
		//renderer.DrawTriangle();
		
		glfwSwapBuffers(renderer.window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}
