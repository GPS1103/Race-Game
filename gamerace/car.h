#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class car : public Drawable{
public:
    car(float X, float Y, int Z);
    ~car()= default;
    int getPs();
    void update(float z);
    int gear=1;
    int rpm=1200;
    float rpmshift(Event event);
    float Ai(int x);
private:
    Texture cartexture;
    Sprite carsprite;
    void draw(RenderTarget& target,RenderStates state)const override;
    Vector2f mv{0, 0};
};
