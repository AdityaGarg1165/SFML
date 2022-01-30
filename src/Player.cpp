#include "Player.h"
#include <iostream>
Player::Player(Texture* texture,Vector2u imageCount,float switchTime,float speed):
    animation(texture,imageCount,switchTime)
{
    this->speed = speed;
    row = 0;
    faceright =true;
    body.setSize(Vector2f(100.0f,100.0f));
    body.setPosition(206.0f,206.0f);
    body.setTexture(texture);
}
void Player::Draw(RenderWindow& window)
{
    window.draw(body);
}
void Player::Update(float deltaTime)
{
    Vector2f movement(0.0f,0.0f);

    if (Keyboard::isKeyPressed(Keyboard::A))
        movement.x -= speed * deltaTime;

    if (Keyboard::isKeyPressed(Keyboard::D))
        movement.x += speed * deltaTime;

    if (movement.x == 0.0f)
    {
        row = 0;

    }
    else
    {
        row = 1;
        if (movement.x > 0.0f)
        {
            faceright = true;
        }
        else
        {
            faceright = false;
        }
        
    }
    animation.update(row,deltaTime,faceright);
    body.setTextureRect(animation.UvRect);
    body.move(movement);
}
