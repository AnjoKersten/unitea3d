#include <iostream>
#include <glad.h>
#include <glfw3.h>

#include "src/renderer.h"
#include "src/shader.h"
#include "src/stb_image.h"
#include "src/camera.h"
#include "src/model.h"
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
	// lampShader
	Shader modelShader("shaders/modelloading.vs", "shaders/modelloading.fs");

<<<<<<< HEAD
	Model carModel("assets/models/lambo/Lamborghini_Aventador.obj");


	unsigned int lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);

	Texture diffuseMap("assets/models/lambo/lambo_diffuse.jpeg");
	Texture specularMap("assets/models/lambo/lambo_spec.jpeg");

	lightShader.use();
	lightShader.setInt("material.diffuse", 0);
	lightShader.setInt("material.specular", 1);
=======
>>>>>>> cccd7c0207b70196cd2bdcaab4618a3974a3f922

	while (!glfwWindowShouldClose(renderer.window))
	{

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// ---------- Input ----------
		processInput(renderer.window);

		// Clear window
		renderer.ClearWindow();

<<<<<<< HEAD
		// Activate Lighting Shaders
		lightShader.use();
		lightShader.setVec3("light.direction", -0.2f, -1.0f, -0.3f);
		lightShader.setVec3("viewPos", camera.Position);

		lightShader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
		lightShader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
		lightShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
		

		lightShader.setFloat("material.shininess", 32.0f);

		//modelShader.use();
=======

		// ---------- Activate Shader ----------
		ourShader.use();
>>>>>>> cccd7c0207b70196cd2bdcaab4618a3974a3f922

		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SWIDTH / (float)SHEIGHT, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		lightShader.setMat4("projection", projection);
		lightShader.setMat4("view", view);

		// render the loaded model
		glm::mat4 model = glm::mat4(1.0f);
<<<<<<< HEAD
		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // translate it down so it's at the center of the scene
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// it's a bit too big for our scene, so scale it down
		lightShader.setMat4("model", model);
		carModel.Draw(lightShader);
=======
		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f));
		model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
		ourShader.setMat4("model", model);
		ourModel.Draw(ourShader);
>>>>>>> cccd7c0207b70196cd2bdcaab4618a3974a3f922


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
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
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