#include "gsprite.h"

GSprite::GSprite()
{
        /** Create "ADDER" empty array and add "ADDER" every addition */
        spritePath = new core::stringc[ADDER];
        clipDimension = new core::rect<u16>[ADDER];
        itemNumberPerSprite = new int[ADDER];
        int count = 0;
        int arrCount = ADDER;
}

void GSprite::addSprite(core::stringc sprite,core::rect<u16> clipDim,
                        int itemNumber)
{

        /** If arrCount%ADDER == 0, we add "ADDER" empty array again
        ** So at the worst case, we have "ADDER-1" unused array
        ** But it makes everything more faster
        **/
        if((arrCount%ADDER)==0) {
                // move the content of (spritePath, clipDimension and itemNumberPerSprite) array to safe place
                core::stringc *spriteTemp = new core::stringc[count];
                core::rect<u16> *clipDimensionTemp = new core::rect<u16>[count];
                int *itemNumberPerSpriteTemp = new int[count];

                for(int i=0; i<count; i++) {
                        spriteTemp[i]=this->spritePath[i];
                        clipDimensionTemp[i]=this->clipDimension[i];
                        itemNumberPerSpriteTemp[i]=this->itemNumberPerSprite[i];
                }
                if(this->spritePath!=NULL)
                        delete[] this->spritePath;
                if(this->clipDimension!=NULL)
                        delete[] this->clipDimension;
                if(this->itemNumberPerSprite!=NULL)
                        delete[] this->itemNumberPerSprite;

                // add "ADDER" empty array
                this->spritePath = new core::stringc[arrCount+ADDER];
                this->clipDimension = new core::rect<u16>[arrCount+ADDER];
                this->itemNumberPerSprite = new int[arrCount+ADDER];

                for(int i=0; i<count; i++) {
                        this->spritePath[i]=spriteTemp[i];
                        this->clipDimension[i]=clipDimensionTemp[i];
                        this->itemNumberPerSprite[i]=itemNumberPerSpriteTemp[i];
                }

                if(spriteTemp!=NULL)
                        delete[] spriteTemp;
                if(clipDimensionTemp!=NULL)
                        delete[] clipDimensionTemp;
                if(itemNumberPerSpriteTemp!=NULL)
                        delete[] itemNumberPerSpriteTemp;

                this->arrCount=this->arrCount+ADDER;
        }
        // add spritePath to spritePath Array
        this->spritePath[count+1] = sprite;
        this->clipDimension[count+1] = clipDim;
        this->itemNumberPerSprite[count+1] = itemNumber;
}

GSprite::~GSprite()
{
        delete[] spritePath;
        delete[] clipDimension;
        delete[] itemNumberPerSprite;
}
