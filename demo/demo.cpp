#include <iostream>
#include <glad.h>
#include <glfw3.h>

#include "src/renderer.h"
#include "src/shader.h"
#include "src/stb_image.h"
#include "src/camera.h"
#include "src/model.h"
#include "src/light.h"
#include "src/vectorx.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SWIDTH / 2.0f;
float lastY = SHEIGHT / 2.0f;
bool firstMouse = true;

// Timing
float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
	Renderer renderer;

	glfwMakeContextCurrent(renderer.window);
	glfwSetCursorPosCallback(renderer.window, mouse_callback);
	glfwSetScrollCallback(renderer.window, scroll_callback);

	glfwSetInputMode(renderer.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	glEnable(GL_DEPTH_TEST);

	// lightShader
	Shader lightShader("shaders/light_caster.vs", "shaders/light_caster.fs");

	Model carModel("assets/models/lambo/Lamborghini_Aventador.obj");
	
	Light directionalLight(DIRECTIONAL_LIGHT, lightShader);

	/*
	unsigned int lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	*/

	directionalLight.SetDiffuseMap("assets/models/lambo/lambo_diffuse.jpeg");
	directionalLight.SetSpecularMap("assets/models/lambo/lambo_spec.jpeg");

	directionalLight.lightShader.use();
	//lightShader.setInt("material.diffuse", 0);
	//lightShader.setInt("material.specular", 1);


	while (!glfwWindowShouldClose(renderer.window))
	{

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// ---------- Input ----------
		processInput(renderer.window);

		// Clear window
		renderer.ClearWindow();

		// Activate Lighting Shaders
		
		directionalLight.UpdateLight(camera);

		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SWIDTH / (float)SHEIGHT, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		directionalLight.lightShader.setMat4("projection", projection);
		directionalLight.lightShader.setMat4("view", view);

		// render the loaded model
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -8.0f, -16.0f)); // translate it down so it's at the center of the scene
		model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));	// it's a bit too big for our scene, so scale it down
		directionalLight.lightShader.setMat4("model", model);
		carModel.Draw(directionalLight.lightShader);

		glfwSwapBuffers(renderer.window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	// FORWARD
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	// BACKWARD
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	// LEFT
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	// RIGHT
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
	// SPRINT
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		camera.ProcessKeyboard(SPRINT, deltaTime);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}