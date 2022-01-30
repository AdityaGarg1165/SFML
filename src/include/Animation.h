#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Animation
{
public:
        Animation(Texture* texture,Vector2u imageCount,float switchtime);
        ~Animation();
        IntRect UvRect;
        void update(int row, float deltatime,bool faceright);

private:
    Vector2u imagecount;
    Vector2u currentimage;

    float totaltime;
    float switchtime;
};