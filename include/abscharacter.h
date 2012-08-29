#ifndef ABSCHARACTER_H
#define ABSCHARACTER_H
#include <irrlicht.h>
#include <Box2D/Box2D.h>
#include <gsprite.h>

using namespace irr;

class AbsCharacter
{
public:
        /** Default constructor */
        AbsCharacter();
        AbsCharacter(b2Vec2 position, b2World *world,
                     GSprite *sprite,video::IVideoDriver *driver);
        /** Get character position at b2box world */
        b2Vec2 getPosition();
        /** Get character position after converted to pixel coordinate*/
        core::vector2d<s32> getPositionI();
        /** Set position of character at b2box world */
        void setPosition(b2Vec2 position);
        /** Set position of character at pixel coordinate. We take care convertion to b2box world position */
        void setPosition(core::vector2d<s32> position);
        /** Set sprite used by character */
        void setSprite(GSprite *spritePath);
        /** Set health character up */
        void upHealth(int up);
        /** Set health of character down */
        void hitHealt(int hit);
        /** Set Driver */
        void setDriver(video::IVideoDriver *driver) { this->driver = driver;}
        /** Gambar ini dong, n itu urutan spritenya */
        void draw(int n);
        /** Default destructor */
        virtual ~AbsCharacter();
protected:
        /** Implementasi fisika bisa menggunakan objek ini, dimanipulasi di class turunan */
        b2Body  *body;      //!< Character body
        /** Implementasikan di class turunan */
        GSprite *spritePath;        //!< Handle basic sprite properties
        /** Urusan irrlich untuk gambar-gambar */
        video::IVideoDriver *driver;
        video::ITexture *texture;
        /** Set up the physic stuff */
        virtual void setPhysic()=0;

private:
        b2BodyDef bodyDef;          //!< Character's bodyDef (check Box2D Documentation)
        b2FixtureDef fixtureDef;    //!< Character's fixtureDef (check Box2D Documentation)
        b2Vec2  position;           //!< Character position at Box2D simulation
        int health;                 //!< Character's healt

//         position2d convertPosition(b2Vec2 position);  //!< Convert position from b2box world to pixel

};

#endif // ABSCHARACTER_H
