#include <SFML/Graphics.hpp>

void updateVelocity(GameObject& obj) {
	obj.setVelocity(obj.getVelocity() + obj.getAcceleration());
}

bool intersects(GameObject& rhs, GameObject& lhs) {
	return rhs.getGlobalBounds.instersects(lhs.getGlobalBounds());
}

