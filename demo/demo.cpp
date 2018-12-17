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
	Shader demoShader("../src/shaders/transformShader.vs", "../src/shaders/sample.fs");

	renderer.CreateCubes(demoShader);

	// Texture 1
	Texture sampleTex("assets/container.png");
	// Texture 2
	Texture awesomeFace("assets/awesomeface.png");
	
	demoShader.use();
	glUniform1i(glGetUniformLocation(demoShader.ID, "texture1"), 0);
	demoShader.setInt("texture2", 1);

	

	while (!glfwWindowShouldClose(renderer.window))
	{
		
		// ---------- Input ----------
		renderer.processInput(renderer.window);


		// ---------- Render ----------
		// Clear window
		renderer.ClearWindow();

		// bind textures on corresponding texture units
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, sampleTex.textureid);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, awesomeFace.textureid);

		// Activate Shader
		demoShader.use();

		// Create Transformations
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		
		//model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		
		projection = glm::perspective(glm::radians(45.0f), (float)SWIDTH / (float)SHEIGHT, 0.1f, 100.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

		renderer.DrawCubes(demoShader);

		// retrieve the matrix uniform locations
		unsigned int modelLoc = glGetUniformLocation(demoShader.ID, "model");
		unsigned int viewLoc = glGetUniformLocation(demoShader.ID, "view");

		demoShader.setMat4("projection", projection);
		demoShader.setMat4("view", view);

		
		
		glfwSwapBuffers(renderer.window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}
