#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{

public:
    Player(Texture* texture,Vector2u imageCount,float switchTime,float speed);
    void Update(float deltaTime);
    void Draw(RenderWindow& window);
private:
    RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceright;


};