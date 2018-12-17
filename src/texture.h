/**
* @file texture.h
*
* @brief The Texture header file
*/

#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <glad.h>
#include <glfw3.h>

#include "src/stb_image.h"
#include "src/shader.h"

/**
 * @brief Texture class lets you put textures on objects
 */
class Texture
{
public:
	/**
	 * @brief Default Transform constructor
	 * @param filePath
	 * Path to desired texture
	 */
	Texture(const char* filePath);

	/**
	 * @brief Default Transform deconstructor
	 */
	virtual ~Texture();

	/**
	 * @brief Content of UpdateTexture must be called and refreshed every frame
	 */
	void UpdateTexture();

	/**
	 * @brief A unique ID every texture has
	 */
	unsigned int textureid;

private:
	int width, height, nrChannels;
	unsigned char *data;

};

#endif