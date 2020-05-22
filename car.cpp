#include <iostream>
#include "car.h"
using namespace std;

car::car(float X, float Y, int Z)
{

carsprite.setPosition(X,Y);
switch(Z){
    case 0:
    if(!cartexture.loadFromFile("car1.png"))cout<<"error loading car texture"<<endl;
    break;
    case 1:
    if(!cartexture.loadFromFile("car2.png"))cout<<"error loading car texture"<<endl;
    break;
    default:
    cout<<"Unable to create"<<endl;
    break;

}
carsprite.setTexture(cartexture);
carsprite.setOrigin(35,15);
}

void car::draw(RenderTarget& target,RenderStates state)const
{
    target.draw(this->carsprite);

}

void car::update(float z)
{
carsprite.move(this->mv);
mv.x+=z;
if(mv.x<0)mv.x=0;
}
int car::getPs()
{
    return carsprite.getPosition().x;
    }
float car::rpmshift(Event event)
{

    float z=0;
    //Odbieranie inputu
    if(Keyboard::isKeyPressed(Keyboard::Up))
  {
  switch(gear)
  {
       case 0:rpm+=50;
      break;
       case 1:rpm+=50;
      break;
       case 2:rpm+=30;
      break;
       case 3:rpm+=15;
      break;
       case 4:rpm+=12;
      break;
       case 5:rpm+=10;
      break;
       case 6:rpm+=8;
      break;
  }
  }
    else rpm-=50;
    if(rpm<1200)rpm=1200;
    if(rpm>9600)rpm=9600;
    /////////
  if (event.type==(Event::KeyPressed)&&event.key.code==Keyboard::A)
   {
       if(gear<6){
      gear+=1;
      rpm-=2500;
      if(rpm<1200)rpm=1200;}
   }
   if (event.type==(Event::KeyPressed)&&event.key.code==Keyboard::Z)
   {
      if(gear>=1){gear-=1;
      rpm+=2500;}}
    ////////Obliczanie Z
       if (Keyboard::isKeyPressed(Keyboard::Down))z=-0.1;
       else
        {switch(gear)
        {
             case 0:z=-0.01;
                break;
             case 1:z=0.0000052*rpm;
                break;
             case 2:z=0.0000070*rpm;
                break;
             case 3:z=0.0000095*rpm;
                break;
             case 4:z=0.0000128*rpm;
                break;
             case 5:z=0.0000173*rpm;
                break;
             case 6:z=0.0000234*rpm;
                break;


        }


                }
return z;
}

float car::Ai(int x)
{
    int rpmmax=0;
    float z=0;
    switch(x)
  {
       case 0:rpmmax=3600;
      break;
       case 1:rpmmax=4600;
      break;
       case 2:rpmmax=5600;
      break;
       case 3:rpmmax=6600;
      break;
       case 4:rpmmax=7700;
      break;
       case 5:rpmmax=8800;
      break;
       case 6:rpmmax=9300;
      break;
  }
 switch(gear)
  {
       case 0:rpm+=50;
      break;
       case 1:rpm+=50;
      break;
       case 2:rpm+=30;
      break;
       case 3:rpm+=15;
      break;
       case 4:rpm+=12;
      break;
       case 5:rpm+=10;
      break;
       case 6:rpm+=8;
      break;
  }
if(rpm<1200)rpm=1200;
if(rpm>rpmmax)rpm=rpmmax;
if(rpm==rpmmax&&gear<6)
{++gear;
rpm-=2500;
}
switch(gear)
        {
             case 0:z=-0.01;
                break;
             case 1:z=0.0000052*rpm;
                break;
             case 2:z=0.0000070*rpm;
                break;
             case 3:z=0.0000095*rpm;
                break;
             case 4:z=0.0000128*rpm;
                break;
             case 5:z=0.0000173*rpm;
                break;
             case 6:z=0.0000234*rpm;
                break;


        }
return z;
}
