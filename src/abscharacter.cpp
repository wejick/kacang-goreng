#include "abscharacter.h"

AbsCharacter::AbsCharacter(b2Vec2 position, b2World *world,
                           GSprite *sprite)
{
        this->position = position;
        this->spritePath = sprite;

        // ngeset-ngeset b2box
        this->bodyDef.position.Set(position.x,position.y);
        this->bodyDef.type = b2_dynamicBody;
        this->body = world->CreateBody(&(this->bodyDef));
}
b2Vec2 AbsCharacter::getPosition()
{
        return this->position;
}
core::position2di AbsCharacter::getPositionI()
{
        // Harus cari algoritmanya konversi dari world b2box ke pixel
}
void AbsCharacter::setPosition(b2Vec2 position)
{
        this->position = position;
}
void AbsCharacter::setPosition(core::position2di position)
{
        // Harus cari algoritmanya konversi dari world b2box ke pixel
}
void AbsCharacter::setSprite(GSprite *spritePath)
{
        this->spritePath = spritePath;
}
void AbsCharacter::upHealth(int up)
{
        this->health=this->health+up;
}
void AbsCharacter::hitHealt(int hit)
{
        this->health=this->health-hit;
}
AbsCharacter::~AbsCharacter()
{
        delete spritePath;
}
