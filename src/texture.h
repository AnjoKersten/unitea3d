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
	Texture(const char *filePath);
	virtual ~Texture();
	void UpdateTexture();
	unsigned int textureid;

private:
	int width, height, nrChannels;
	unsigned char *data;

};

#endif