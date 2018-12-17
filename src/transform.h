/**
* @file transform.h
*
* @brief The Transform header file
*/

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "src/vectorx.h"

/**
 * @brief Transform class for transforming objects
 */
class Transform
{
public:
	/**
	 * @brief Default Transform constructor
	 */
	Transform();

	/**
	 * @brief Default Transform deconstructor
	 */
	virtual ~Transform();

	/**
	 * @brief Vector3 with the postion of the attached object
	 */
	Vector3 position;

	/**
	 * @brief Vector3 with the scale of the attached object
	 */
	Vector3 scale;


private:

};

#endif