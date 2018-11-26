#include <iostream>
#include <glad.h>
#include <glfw3.h>
#include "src/renderer.h"
#include "src/shader.h"
#include "src/stb_image.h"
#include "src/vectorx.h"

int main()
{
	Renderer renderer;
	Shader demoShader("../src/shaders/sample.vs", "../src/shaders/sample.fs");
	
	Vector2 vec2 = Vector2(10, 20);
	Vector3 vec3 = Vector3(42, 42, 42);
	Vector3d vec3d = Vector3d(2.22, 2.22, 2.22);
	Vector3 newvec;
	newvec.Add(vec3);
	float sqrtVec = vec3.GetLength();

	vec2.display();
	vec3.display();
	vec3d.display();
	newvec.display();
	
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
