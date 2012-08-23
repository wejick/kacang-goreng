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

        AbsCharacter(b2Vec2 position, b2World world,
                     GSprite sprite);
        /** Get character position at b2box world */
        b2Vec2 getPosition();
        /** Get character position after converted to pixel coordinate*/
        core::position2di getPositionI;
        /** Get current path of active sprite */
        core::string<fschar_t> getActiveSprite();
        /** Set position of character at b2box world */
        void setPosition(b2Vec2 position);
        /** Set position of character at pixel coordinate. We take care convertion to b2box world position */
        void setPosition(core::position2di position);
        /** Set sprite used by character */
        void setSprite(GSprite spritePath);
        /** Set health character up */
        void upHealth(int up);
        /** Set health of character down */
        void hitHealt(int hit);

		/** Default destructor */
		virtual ~AbsCharacter();
	protected:
        b2Body  *body;      //!< Character body
        b2Vec2  position;   //!< Character position at Box2D simulation
        GSprite spritePath; //!< Handle basic sprite properties
	private:
        b2BodyDef bodyDef;          //!< Character's bodyDef (check Box2D Documentation)
        b2FixtureDef fixtureDef;    //!< Character's fixtureDef (check Box2D Documentation)
//        b2Shape shape;               //!< Character's shape
        int health;                 //!< Character's healt

};

#endif // ABSCHARACTER_H
