#include "rectangle.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

// struct Vector2f
// {
//     float x;
//     float y;
// };

Vector2f speed ={3.f, 3.f};

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    Rectangle shape(Vector2f(50.f, 30.f));
    window.setFramerateLimit(60);
    vector<Rectangle> rectangulos;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            
            if (event.type == event.MouseButtonPressed)
            {
                if(event.mouseButton.button == Mouse::Left)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;

                    Rectangle rec(Vector2f(50.f,30.f), x, y);
                    rectangulos.push_back(rec);
                }

                if (event.mouseButton.button == Mouse::Right)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;

                    for (auto &r : rectangulos)
                    {
                        r.click(x, y);
                    }
                }
            }
        }

        window.clear();
        shape.update();
        shape.drawTo(window);
        for (auto &r : rectangulos)
        {
            r.update();
            r.drawTo(window);
        }
        window.display();
    }

    return 0;
}