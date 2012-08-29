#ifndef CHAR_H
#define CHAR_H

#include <abscharacter.h>


class Char : public AbsCharacter
{
    public:
        /** Default constructor */
        Char();
        Char(b2Vec2 position, b2World *world,video::IVideoDriver *driver);
        //void draw(int n);
        /** Default destructor */
        virtual ~Char();
    protected:
    private:
        void setPhysic();
        GSprite *sprite;
        b2World *world;
};

#endif // CHAR_H
