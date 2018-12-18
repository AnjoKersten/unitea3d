/**
* @file gameobject.h
*
* @brief The GameObject header file
*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

/**
 * @brief GameObjects have the following properties:
 *
 * Transform: position, rotation, scale
 *
 * Mesh/Model
 */
class GameObject
{
public:
	/**
	 * @brief Default GameObject constructor
	 */
	GameObject();
	/**
	 * @brief Default GameObject deconstructor
	 */
	virtual ~GameObject();

private:

};

#endif