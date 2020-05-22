#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class licznik:public Drawable
{
    public:
        licznik();
        ~licznik()=default;
       void update(float posistion, int rpm);
   private:
        Texture disptexture;
        Sprite dispsprite;
        void draw(RenderTarget& target,RenderStates state)const override;
        Vector2f location{0,800};
        Texture ArrowTx;
        Sprite ArrowSprite;
};
