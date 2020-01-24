#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "../Object systems/GameObject.hpp"

void updateVelocity(GameObject& obj);

//bool intersects(GameObject& rhs, GameObject& lhs);

bool isObjOnGround(GameObject& movingObj, GameObject& staticObj);

bool isLeftIntersecting(GameObject& movingObj, GameObject& staticObj);

bool isRightIntersecting(GameObject& movingObj, GameObject& staticObj);

bool isTopIntersecting(GameObject& movingObj, GameObject& staticObj);

//bool intersects(GameObject& rhs, ObjectBlock& lhs);

bool isObjOnGround(GameObject& movingObj, ObjectBlock& staticObj);

bool isLeftIntersecting(GameObject& movingObj, ObjectBlock& staticObj);

bool isRightIntersecting(GameObject& movingObj, ObjectBlock& staticObj);

bool isTopIntersecting(GameObject& movingObj, ObjectBlock& staticObj);

#endif //PHYSICS_HPP