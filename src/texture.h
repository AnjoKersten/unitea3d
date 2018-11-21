#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <glad.h>
#include <glfw3.h>

#include "src/stb_image.h"
#include "src/shader.h"

class Texture
{
public:
	Texture();
	virtual ~Texture();
	void SetPath(char *texturePath);
	unsigned int textureid;

private:
	int width, height, nrChannels;
	unsigned char *data;
	char imagePath = NULL;

};

#endif