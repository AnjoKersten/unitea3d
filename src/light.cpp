#include "light.h" 
 
Light::Light(LightType lightType, Shader shader)
{
	type = lightType;
	lightShader = shader;

	unsigned int lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
}
 
Light::~Light(){

}

void Light::SetDiffuseMap(const char *texturePath)
{
	Texture diffuseMap(texturePath);
	glActiveTexture(GL_TEXTURE0);
	lightShader.setInt("material.diffuse", 0);

}

void Light::SetSpecularMap(const char *texturePath)
{
	Texture specularMap(texturePath);
	glActiveTexture(GL_TEXTURE1);
	lightShader.setInt("material.specular", 1);
}

void Light::UpdateLight(Camera camera)
{
	if (type == DIRECTIONAL_LIGHT)
	{
		lightShader.use();
		lightShader.setVec3("light.direction", -4.0f, -16.0f, -6.0f);
		lightShader.setVec3("viewPos", camera.Position);

		lightShader.setVec3("light.ambient", 0.25f, 0.25f, 0.25f);
		lightShader.setVec3("light.diffuse", 0.8f, 0.8f, 0.8f);
		lightShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);


		lightShader.setFloat("material.shininess", 32.0f);
	}
	else
	{
		// do nothing...
	}
	
}