#include <Animation.h>
#include <iostream>

Animation::Animation(Texture* texture,Vector2u imageCount,float switchtime)
{
    this->imagecount = imageCount;
    this->switchtime = switchtime;
    totaltime = 0;
    currentimage.x = 0;
    UvRect.width = texture->getSize().x/float(imageCount.x);
    UvRect.height = texture->getSize().y/float(imageCount.y);
}
Animation::~Animation()
{}
void Animation::update(int row, float deltatime,bool faceright)
{
    currentimage.y = row;
    totaltime += deltatime;

    if (totaltime >= switchtime)
    {

        totaltime -= switchtime;
        currentimage.x++;
    }
    if (currentimage.x >= imagecount.x)
    {
        currentimage.x = 0;
    }
    
    UvRect.top = currentimage.y * UvRect.height;

    if (faceright)
    {
        UvRect.left = currentimage.x * UvRect.width;
        UvRect.width = abs(UvRect.width);
    }
    else
    {
        UvRect.left = (currentimage.x + 1) * abs(UvRect.width);
        UvRect.width = -abs(UvRect.width);
    }

}