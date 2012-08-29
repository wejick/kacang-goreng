#include "abscharacter.h"

AbsCharacter::AbsCharacter()
{
        this->position.Set(0.0f,0.0f);
}
AbsCharacter::AbsCharacter(b2Vec2 position, b2World *world,
                           GSprite *spritePath,video::IVideoDriver *driver)
{
        // ngeset-ngeset properti
        this->position = position;
        this->spritePath = spritePath;

        //ngeset irrlicht
        this->driver = driver;

        // ngeset-ngeset b2box
        this->bodyDef.position.Set(position.x,position.y);
        this->bodyDef.type = b2_dynamicBody;
        this->body = world->CreateBody(&(this->bodyDef));
}
b2Vec2 AbsCharacter::getPosition()
{
        this->position = this->body->GetPosition();
        return this->position;
}
irr::core::vector2d<s32> AbsCharacter::getPositionI()
{
        // Harus cari algoritmanya konversi dari world b2box ke pixel
        this->position = this->body->GetPosition();
        /** sementara ini dulu (+5) */
        core::vector2d<s32> pos = core::vector2d<s32>(this->position.x+5,this->position.y+5);
        return pos;
}
void AbsCharacter::setPosition(b2Vec2 position)
{
        this->position = position;
}
void AbsCharacter::setPosition(core::vector2d<s32> position)
// TODO (gio#1#): Mbenerin posisi antara b2box VS irrlich{
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
void AbsCharacter::setPhysic()
{

}
void AbsCharacter::setSprite(GSprite *spritePath)
{
        this->spritePath = spritePath;
}
void AbsCharacter::draw(int n)
{

}
AbsCharacter::~AbsCharacter()
{
        delete this->spritePath;
        delete this->driver;
        delete this->texture;
}
