/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/Enemy0Base.hpp>
#include <BitmapDatabase.hpp>

Enemy0Base::Enemy0Base()
{
    setWidth(30);
    setHeight(26);
    animatedImage.setXY(0, 0);
    animatedImage.setBitmaps(BITMAP_ENEMY0_ID, BITMAP_ENEMY0_ID);
    animatedImage.setUpdateTicksInterval(1);

    add(animatedImage);
}

Enemy0Base::~Enemy0Base()
{

}

void Enemy0Base::initialize()
{

}

