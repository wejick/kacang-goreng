#include "gsprite.h"

using namespace irr;

int main(){
    GSprite *ok = new GSprite;
    ok->addSprite("hore",core::rect<u16>(12,12,12,12),12);
    ok->addSprite("hoare",core::rect<u16>(12,12,12,12),12);
    ok->addSprite("hodre",core::rect<u16>(12,12,12,12),12);
    ok->addSprite("hosre",core::rect<u16>(12,12,12,12),12);
    return 0;
}
