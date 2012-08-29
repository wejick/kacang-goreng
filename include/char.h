#ifndef CHAR_H
#define CHAR_H

#include <abscharacter.h>


class Char : public AbsCharacter
{
    public:
        /** Default constructor */
        Char();
        Char(b2Vec2 position, b2World *world);
        /** Default destructor */
        virtual ~Char();
    protected:
    private:
        GSprite *sprite;
        void setPhysic();
        b2World *world;
};

#endif // CHAR_H
