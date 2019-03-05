#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <glad.h>
#include <glfw3.h>

#include "src/model.h"
#include "src/shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Entity
{
public:
	Entity();
	virtual ~Entity();

	glm::vec3 position; // position with x, y, z values
	glm::vec3 scale; // scale for x, y, z axis

	// ------------ These functions should be called every frame ------------
	void LinkModel(Model model);
	void LinkModel(Model usedModel, Shader usedShader);
	// ----------------------------------------------------------------------



private:

};

#endif