/**
* @file renderer.h
*
* @brief The Renderer header file
*/

#ifndef RENDERER_H
#define RENDERER_H

#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "src/u3dconfig.h"
#include "src/stb_image.h"
#include "src/shader.h"
#include "src/texture.h"
#include "src/camera.h"

/**
 * @brief Renderer class for creating a Window and drawing different shapes
 */
class Renderer
{
	public:
		/**
		* @brief Default Renderer constructor
		*/
		Renderer();
		/**
		* @brief Default Renderer deconstructor
		*/
		virtual ~Renderer();
		/**
		* @brief Pointer to a GLFWwindow
		*/
		GLFWwindow* window;

		/**
		* @brief Process input for the given window pointer
		* @param window
		* GLFWwindow to get input from
		*/
		//void processInput(GLFWwindow* window, Camera cam);

		/**
		* @brief Create Cubes with the given shader
		* @param usedShader
		* Shader used for creating the cubes
		*/
		void CreateCubes(Shader usedShader);

		/**
		* @brief Draw Cubes with the given shader
		* @param usedShader
		* Shader used for drawing the cubes
		*/
		void DrawCubes(Shader usedShader);

		/**
		* @brief Create a Rectangle
		*/
		void CreateRectangle();

		/**
		* @brief Draw a Rectangle
		*/
		void DrawRectangle();

		/**
		* @brief Create a Triangle
		*/
		void CreateTriangle();

		/**
		* @brief Draw a Triangle
		*/
		void DrawTriangle();

		/**
		* @brief Clear current used GLFWwindow
		*/
		void ClearWindow();

		// timing
		float deltaTime = 0.0f;	// time between current frame and last frame
		float lastFrame = 0.0f;

	private:
		unsigned int VBO, VAO, EBO;
};

#endif