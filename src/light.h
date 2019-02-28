#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <glad.h>
#include <glfw3.h>

#include "src/shader.h"
#include "src/texture.h"
#include "src/camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum LightType
{
	DIRECTIONAL_LIGHT, 
	POINT_LIGHT,
	SPOT_LIGHT
};

class Light
{
public:
	
	LightType type;
	Shader lightShader;

	Light(LightType lightType, Shader shader);
	virtual ~Light();

	void UpdateLight(Camera camera);
	void SetDiffuseMap(const char *texturePath);
	void SetSpecularMap(const char *texturePath);
	

private:

};

#endif