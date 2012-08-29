#include "char.h"

Char::Char() : AbsCharacter::AbsCharacter()
{
        //ctor
}
Char::Char(b2Vec2 position, b2World *world) :
        AbsCharacter::AbsCharacter(position,world,NULL)
{
        this->world = world;
        Char::setPhysic();
        this->sprite = new GSprite();
        this->sprite->addSprite("../../logistik/project/tutorial_a/ok.jpg", irr::core::rect<u16>(0,0,600,433),1);
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
        bodyFixDef.friction = 0.4f;

        AbsCharacter::body->CreateFixture(&bodyFixDef);
}
Char::~Char()
{
        //dtor
}
