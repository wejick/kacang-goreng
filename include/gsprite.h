#ifndef GSPRITE_H
#define GSPRITE_H
#include <irrlicht.h>
#include <Box2D/Box2D.h>

using namespace irr;
class GSprite
{
	public:
		/** Default constructor */
		GSprite();
		/** Add sprite and its specification to Array of spritePath */
		void addSprite(core::string<fschar_t> spritePath,core::rect<u16> clipDimension,
					int itemNumberPerSprite);
		/** Get sprite path value at any given number (from spritePath array) */
		core::string<fschar_t> getSprite(int number);
		int getCount() { return count; }
		/** Get amount of item value at any given number (from spritePath array) */
		int getItemNumberPerSprite(int number);

		/** Default destructor */
		virtual ~GSprite();

	protected:
	private:
		core::string<fschar_t> *spritePath; //!< Array for sprite path
		core::rect<u16> *clipDimension; //!< Array for clip dimension for sprite's items
		int *itemNumberPerSprite; //!< Number to show how much item per sprite
		int count; //!< How much sprite you have boy?
		int arrCount; //!< The real sum of array
};

#endif // GSPRITE_H
