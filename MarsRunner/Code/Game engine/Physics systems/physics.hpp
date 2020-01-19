#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "../Object systems/GameObject.hpp"

void updateVelocity(GameObject& obj);

bool intersects(GameObject& rhs, GameObject& lhs);

bool isObjOnGround(GameObject& movingObj, GameObject& staticObj);

bool isLeftIntersecting(GameObject& movingObj, GameObject& staticObj);

bool isRightIntersecting(GameObject& movingObj, GameObject& staticObj);

bool isTopIntersecting(GameObject& movingObj, GameObject& staticObj);

#endif //PHYSICS_HPP