#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "../Object systems/GameObject.hpp"
#include <SFML/Graphics.hpp>

/// \brief
/// Physics class

/// \details
/// The Physics class handles most of the Physics related calculations of the game

void updateVelocity(GameObject& obj);

bool isObjOnGround(GameObject& movingObj, GameObject& staticObj);

bool isLeftIntersecting(GameObject& movingObj, GameObject& staticObj);

bool isRightIntersecting(GameObject& movingObj, GameObject& staticObj);

bool isTopIntersecting(GameObject& movingObj, GameObject& staticObj);

bool isObjOnGround(GameObject& movingObj, ObjectBlock& staticObj);

bool isLeftIntersecting(GameObject& movingObj, ObjectBlock& staticObj);

bool isRightIntersecting(GameObject& movingObj, ObjectBlock& staticObj);

bool isTopIntersecting(GameObject& movingObj, ObjectBlock& staticObj);

bool isLeftIntersecting(GameObject& movingObj, sf::FloatRect viewBounds);

bool isRightIntersecting(GameObject& movingObj, sf::FloatRect viewBounds);

#endif //PHYSICS_HPP