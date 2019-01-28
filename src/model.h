#ifndef MODEL_H
#define MODEL_H

#include <glad.h>

#include "src/shader.h"
#include "src/mesh.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <src/stb_image.h>
#include <Importer.hpp>
#include <scene.h>
#include <postprocess.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

class Model
{
public:
	std::vector<Texture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;
	bool gammaCorrection;

	Model(std::string const &path, bool gamma = false);

	void Draw(Shader shader);

private:

	void loadModel(std::string const &path);

	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
	unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);
};

#endif