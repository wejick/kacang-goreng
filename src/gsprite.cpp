#include "gsprite.h"

GSprite::GSprite() {
        /** Create 3 empty array and add 3 every addition */
		spritePath = new core::string<fschar_t>[3];
		clipDimension = new core::rect<u16>[3];
		itemNumberPerSprite = new int[3];
		int count = 0;
		int arrCount = 3;
}
void GSprite::addSprite(core::string<fschar_t> sprite,core::rect<u16> clipDim,
                        int itemNumber) {

        /** If arrCount%adder == 0, we add "adder" empty array again
        ** So at the worst case, we have "adder-1" unused array
        ** But it makes everything more faster
        **/
        // How much array we add ?
        int adder = 3;
        if((arrCount%adder)==0){
            // move the content of (spritePath, clipDimension and itemNumberPerSprite) array to safe place
            core::string<fschar_t> *spriteTemp = new core::string<fschar_t>[count];
            core::rect<u16> *clipDimensionTemp = new core::rect<u16>[count];
            int *itemNumberPerSpriteTemp = new int[count];

            for(int i=0;i<count;i++){
                spriteTemp[i]=spritePath[i];
                clipDimensionTemp[i]=clipDimension[i];
                itemNumberPerSpriteTemp[i]=itemNumberPerSpriteTemp[i];
            }

            delete spritePath;
            delete clipDimension;
            delete itemNumberPerSprite;

            // add "adder" empty array
            spritePath = new core::string<fschar_t>[arrCount+adder];
            clipDimension = new core::rect<u16>[arrCount+adder];
            itemNumberPerSprite = new int[arrCount+adder];

            for(int i=0;i<count;i++){
                spritePath[i]=spriteTemp[i];
                clipDimension[i]=clipDimensionTemp[i];
                itemNumberPerSprite[i]=itemNumberPerSpriteTemp[i];
            }

            delete spriteTemp;
            delete clipDimensionTemp;
            delete itemNumberPerSpriteTemp;

            arrCount=arrCount+adder;
        }
        // add spritePath to spritePath Array
        spritePath[count+1] = sprite;
        clipDimension[count+1] = clipDim;
        itemNumberPerSprite[count+1] = itemNumber;
}
GSprite::~GSprite() {
    delete spritePath;
    delete clipDimension;
    delete itemNumberPerSprite;
}
