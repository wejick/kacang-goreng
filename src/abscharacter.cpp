#include "abscharacter.h"

AbsCharacter::AbsCharacter()
{
        this->position.Set(0.0f,0.0f);
}
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
irr::core::vector2d<s32> AbsCharacter::getPositionI()
{
        // Harus cari algoritmanya konversi dari world b2box ke pixel
        /** sementara ini dulu (+5) */
        core::vector2d<s32> pos = core::vector2d<s32>(this->position.x+5,this->position.y+5);
        return pos;
}
void AbsCharacter::setPosition(b2Vec2 position)
{
        this->position = position;
}
void AbsCharacter::setPosition(core::vector2d<s32> position)
{
        // Harus cari algoritmanya konversi dari world b2box ke pixel
        /** sementara ini dulu (-5) */
        this->position.x = position.X-5;
        this->position.y = position.Y-5;
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
