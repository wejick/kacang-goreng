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
        this->sprite->addSprite("../../logistik/project/tutorial_a/ok.jpg", irr::core::rect<u16>(0,66,200,133),1);
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
void Char::draw(video::IVideoDriver *driver)
{
        irr::video::ITexture *texture = driver->getTexture(this->spritePath->getSprite(1)); // ini bisa bikin lambat, harus ngeload sekali (atau pas dibutuhkan) saja
        irr::core::vector2d<s32> ok = this->getPositionI();
        driver->makeColorKeyTexture(texture,core::vector2d<s32>(0,0));
        driver->draw2DImage(texture,ok,core::rect<s32>(200,200,442,400));
}
Char::~Char()
{
        //dtor
}
