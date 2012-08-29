#include "char.h"
#include "Box2D/Box2D.h"
#include "irrlicht.h"

using namespace irr;

int main()
{
        const b2Vec2 gravity(0.0f,-10.0f);

        bool doSleep=true;
        b2World world = b2World(gravity);

        //buat ground body def
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(0.0f,-10.0f);

        //buat ground body yang beneran dan tambahkan ke world
        b2Body *groundBody = world.CreateBody(&groundBodyDef);

        //buat shape
        b2PolygonShape groundBox;
        groundBox.SetAsBox(50.0f,10.0f);

        //tambah fixture ke body dengan groundbox sebagai shape
        groundBody->CreateFixture(&groundBox,0.0f);

        /** masalah irrlichnya */
        Char *mainChar = new Char(b2Vec2(5.0f,7.0f),&world);
        IrrlichtDevice *device = createDevice(video::EDT_OPENGL,core::dimension2d<u32>(640,480),16,false,false,false,NULL);
        if(!device)
                return 1;
        video::IVideoDriver *driver = device->getVideoDriver();
        float32 timeStep = 1.0f / 60.0f;
        int32 velocityIteration = 1;
        int32 positionIteration = 1;

        b2Vec2 position;
        //for (int32 i = 0; i < 120; ++i) {
        while(1) {
                world.Step(timeStep, velocityIteration, positionIteration);
                driver->beginScene(true,true,video::SColor(255,225,225,255));
                mainChar->draw(driver);
                driver->endScene();
        }
        return 0;
}
