#include <iostream>
#include "display.h"

licznik::licznik()
{
dispsprite.setPosition(620,800);
if(!disptexture.loadFromFile("disp_bg.png"))cout<<"error loading display texture"<<endl;
dispsprite.setTexture(disptexture);

ArrowSprite.setPosition(770,900);
ArrowSprite.setOrigin(10,100);
if(!ArrowTx.loadFromFile("disp_arr.png"))cout<<"error loading display arrow texture"<<endl;
ArrowSprite.setTexture(ArrowTx);


}


void licznik::update(float posistion, int rpm)
{
    location.x=posistion;
   dispsprite.setPosition(this->location);
   ArrowSprite.setPosition(posistion+150,900);
   ArrowSprite.setRotation((rpm/70)-90);

}



void licznik::draw(RenderTarget& target,RenderStates state)const
{
    target.draw(this->dispsprite);
    target.draw(this->ArrowSprite);

}
