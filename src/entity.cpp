#include "entity.h" 
 
Entity::Entity()
{
	position = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);
}
 
Entity::~Entity()
{

}

void Entity::LinkModel(Model usedModel)
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, scale);
	usedModel.usedShader.setMat4("model", model);
	//usedModel.Draw(usedModel.usedShader);
}

void Entity::LinkModel(Model usedModel, Shader usedShader)
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, scale);
	usedModel.usedShader.setMat4("model", model);
	usedModel.Draw(usedShader);
}