#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(510,510),"jkj");
    Texture playertex;
    playertex.loadFromFile("res/gfx//player.png");
    playertex.setSmooth(true);

    Player player(&playertex,Vector2u(3,10),0.3f,100.0f);

    float deltatime = 0.0f;
    Clock clock;

    // Vector2u playersize = playertex.getSize();
    // playersize.x /=4;
    // playersize.y /=3;
    // player.setTextureRect(IntRect(playersize.x * 2,playersize.y * 2,playersize.x,playersize.y));


    while(window.isOpen())
    {   Event evnt;
        deltatime = clock.restart().asSeconds();
        while(window.pollEvent(evnt))
        {
            if (evnt.type == evnt.Closed)
            {
                window.close();
            }
            
        }
        player.Update(deltatime);
        
    
        
        window.clear(Color::White);
        player.Draw(window);
        window.display();
    }
    return 0;
}