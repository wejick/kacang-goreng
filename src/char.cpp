#include "char.h"

Char::Char() : AbsCharacter::AbsCharacter()
{
        //ctor
}
Char::Char(b2Vec2 position, b2World *world,video::IVideoDriver *driver) :
        AbsCharacter::AbsCharacter(position,world,NULL,driver)
{
        this->world = world;
        Char::setPhysic();
        this->sprite = new GSprite();
        this->sprite->addSprite("../../logistik/project/tutorial_a/ok.jpg", irr::core::rect<s32>(0,66,200,133),1);
        AbsCharacter::setSprite(sprite);
}
void Char::setPhysic()
{
        //buat shapenya body
        b2PolygonShape bodyShape;
        bodyShape.SetAsBox(1.0f,1.0f);
        //fixturenya batu
        b2FixtureDef bodyFixDef;
        bodyFixDef.shape = &bodyShape;
        bodyFixDef.density = 2.0f;
        bodyFixDef.friction = 0.1f;

        AbsCharacter::body->CreateFixture(&bodyFixDef);
}
Char::~Char()
{
        //dtor
}
