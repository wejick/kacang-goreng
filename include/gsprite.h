#ifndef GSPRITE_H
#define GSPRITE_H
#define ADDER 3
#include <irrlicht.h>
#include <Box2D/Box2D.h>

using namespace irr;
class GSprite
{
	public:
		/** Default constructor */
		GSprite();
		/** Add sprite and its specification to Array of spritePath */
		void addSprite(core::stringc spritePath,core::rect<s32> clipDimension,
					int itemNumberPerSprite);
		/** Get sprite path value at any given number (from spritePath array) */
		core::stringc getSprite(int number) {return spritePath[number];}
		/** Get clip dimension */
		core::rect<s32> getClipDimension(int n){ return clipDimension[n]; }
		int getCount() { return count; }
		/** Get amount of item value at any given number (from spritePath array) */
		int getItemNumberPerSprite(int number){return itemNumberPerSprite[number];}
		/** Default destructor */
		virtual ~GSprite();

	protected:
	private:
		core::stringc *spritePath; //!< Array for sprite path
		core::rect<s32> *clipDimension; //!< Array for clip dimension for sprite's items
		int *itemNumberPerSprite; //!< Number to show how much item per sprite
		int count; //!< How much sprite you have boy?
		int arrCount; //!< The real sum of array
};

#endif // GSPRITE_H
