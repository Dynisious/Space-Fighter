#include "Entity.h"

Space_Fighter::EntityTypes::Entity::Entity(const CollidableObject & collide, const PositionObject & pos)
	: CollidableObject(collide), PositionObject(pos) {}

Space_Fighter::EntityTypes::Entity::Entity(const Entity & orig) : CollidableObject(orig), PositionObject(orig) {}

Space_Fighter::EntityTypes::Entity::~Entity() {}
