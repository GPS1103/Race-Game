#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "car.h"
#include "display.h"
#include <windows.h>
#include "menu.h"
using namespace sf;
using namespace std;
void countdown(RenderWindow* game,Sprite bg_sprite,Text* text2,car auto1,car auto2,licznik disp)
{
     CircleShape Circle1(100);
    CircleShape Circle2(100);
    CircleShape Circle3(100);
     Circle1.setPosition(500,450);
Circle2.setPosition(700,450);
Circle3.setPosition(900,450);
Circle1.setFillColor( Color::Red);
Circle2.setFillColor(Color::Yellow);
Circle3.setFillColor(Color::Green);

text2->setPosition(770,860);


game->draw(bg_sprite);
game->draw(disp);
game->draw(*text2);
game->draw(auto1);
game->draw(auto2);
game->draw(Circle1);
game->display();
Sleep(1000);
//3
game->draw(bg_sprite);
game->draw(disp);
game->draw(*text2);
game->draw(auto1);
game->draw(auto2);
game->draw(Circle1);
game->draw(Circle2);
game->display();
////2
Sleep(1000);
game->draw(bg_sprite);
game->draw(disp);
game->draw(*text2);
game->draw(auto1);
game->draw(auto2);
game->draw(Circle1);
game->draw(Circle2);
game->draw(Circle3);
Sleep(1000);
////1
game->display();
Sleep(500);

    }


    void endgame(Text* text,Event event)
    {


RenderWindow fin(VideoMode(800,600),"Ukonczyles");
  fin.setFramerateLimit(60);
  while(true){
text->setPosition(300,250);
  fin.draw(*text);
 fin.display();
 fin.clear();
fin.pollEvent(event);
     if(event.type==Event::Closed)
     {
         fin.close();
         break;
     }
  if(Keyboard::isKeyPressed(Keyboard::Enter)||Keyboard::isKeyPressed(Keyboard::Escape))
  {
      fin.close();
      break;
  }
  }

    }




int race(RenderWindow* game,Sprite bg_sprite,car auto1,car auto2,licznik disp,View view,Event event,Vector2f posistion,Text* text2,Text* text,int lvl)
{
    int rtnvalue=0;
 while(true)
 {

     game->setView(view);
     game->clear();
     game->draw(bg_sprite);
     game->pollEvent(event);
     if(event.type==Event::Closed)
     {
         game->close();
         break;
     }
    text2->setString(to_string(auto1.gear));
     auto1.update(auto1.rpmshift(event));
    auto2.update(auto2.Ai(lvl));
    posistion.x=auto1.getPs()-800;
    if(posistion.x<0)posistion.x=0;
    view.reset(FloatRect(posistion.x,0,1600,900));
   text2->setPosition(posistion.x+770,860);
   disp.update(posistion.x+620, auto1.rpm);
   game->draw(disp);
    game->draw(*text2);
    game->draw(auto1);
    game->draw(auto2);
     game->display();

if(posistion.x>14400)
{
text->setString("You Won!");
rtnvalue=1;
  break;

}
if((auto2.getPs()-800)>14400)
{
text->setString("You Lost!");
rtnvalue=0;
  break;

}
 }
 auto1.gear=1;
 auto2.gear=1;
 view.reset(FloatRect(0,0,1600,900));
 game->setView(view);
 endgame(text,event);
 Sleep(150);
 return rtnvalue;
}




void campagin(RenderWindow* game,Sprite bg_sprite,car auto1, car auto2,licznik disp,View view,Event event,Vector2f posistion,Text* text2,Text* text)
{
     for(int i=0; i<7;i++){
countdown(game,bg_sprite,text2,auto1,auto2,disp);
if(!race(game,bg_sprite,auto1,auto2,disp,view,event,posistion,text2,text,i))
{
   text->setString("You lost the campaign!!!");
    break;
}
if(i==6)text->setString("You won the campaign!!!");
 }
    text->setCharacterSize(50);
    text->setPosition(550,450);
 while(game->isOpen())
 {
     game->pollEvent(event);
     if(event.type==Event::Closed)
     {
         game->close();
         break;
     }
     if(Keyboard::isKeyPressed(Keyboard::Escape)||Keyboard::isKeyPressed(Keyboard::Enter))
  {
      break;
  }

 game->clear(Color::Black);
 game->draw(*text);
 game->display();
}}





int main()
{

        int lvl=50;
     Texture bg_texture;
     Sprite bg_sprite;
     Texture mn_texture;
     Sprite mn_sprite;
     Vector2f posistion{0,0};
     Font font;
     View view;
     Event event;
     Text text2("0",font,35);
     licznik disp;
     car auto1(50,400,0);
     car auto2(50,250,1);
     Text text("0",font,50);
     Menu menu(1300,900);
     Menu menu2(1300,900);
     menu2.Setmenucase("Easy","Normal","Hard","Very Hard");
 RenderWindow game(VideoMode(1600,900),"Race Game");
 game.setFramerateLimit(60);
  if(!bg_texture.loadFromFile("background.png"))
 {
     cout<<"Nie mozna wczytac tla"<<endl;
 }
 bg_sprite.setTexture(bg_texture);
 bg_sprite.setScale(1.0f, 900/bg_texture.getSize().y);

   if(!mn_texture.loadFromFile("menu.png"))
 {
     cout<<"Nie mozna wczytac tla"<<endl;
 }
 mn_sprite.setTexture(mn_texture);
 mn_sprite.setScale(1.0f, 900/mn_texture.getSize().y);

 if (!font.loadFromFile("arial.ttf")) return EXIT_FAILURE;
 view.reset(FloatRect(0,0,1600,900));
 Text credits[5];
    for(int i=0;i<4;i++)
    {
    credits[i].setFont(font);
	credits[i].setColor(Color::Black);
	credits[i].setPosition(500,900/6*(i+1));
	credits[i].setCharacterSize(45);
    }
    credits[0].setString("CREDITS");
    credits[1].setString("Car's Graphics - chasersgaming");
    credits[2].setString("Menu Background Graphics - OhjiroChan");
    credits[3].setString("Everything else - Grzegorz Sot");

 while(true)

 {

     game.pollEvent(event);
     if(event.type==Event::Closed)
     {
         game.close();
         break;
     }
     if(Keyboard::isKeyPressed(Keyboard::Up))
     {menu.MoveUp();
        Sleep(150);
     }
     if(Keyboard::isKeyPressed(Keyboard::Down))
     {menu.MoveDown();
        Sleep(150);
     }
      if(Keyboard::isKeyPressed(Keyboard::Enter))
     {
         switch(menu.GetPressedItem())
         {
             case 0:campagin(&game,bg_sprite,auto1,auto2,disp,view,event,posistion,&text2,&text);
                    Sleep(150);
                    break;
             case 1:Sleep(150);
                    while(true)
                    {
                        game.pollEvent(event);
                            if(event.type==Event::Closed)
                                {
                                    game.close();
                                    break;
                                    }
                        if(Keyboard::isKeyPressed(Keyboard::Up))
                        {menu2.MoveUp();
                            Sleep(150);
                        }
                        if(Keyboard::isKeyPressed(Keyboard::Down))
                        {menu2.MoveDown();
                        Sleep(150);
                        }
                         if(Keyboard::isKeyPressed(Keyboard::Escape))
                        {
                        Sleep(150);
                        break;
                        }
                         if(Keyboard::isKeyPressed(Keyboard::Enter))
                        {
                        switch(menu2.GetPressedItem())
                        {
                            case 0:lvl=0;
                            break;
                            case 1:lvl=3;
                            break;
                            case 2:lvl=5;
                            break;
                            case 3:lvl=6;
                            break;
                        }
                        break;}

                        game.clear(Color::Black);
                        game.draw(mn_sprite);
                        menu2.draw(&game);
                        game.display();

                    }
                    if(lvl!=50){
                    countdown(&game,bg_sprite,&text2,auto1,auto2,disp);
                    race(&game,bg_sprite,auto1,auto2,disp,view,event,posistion,&text2,&text,lvl);
                    lvl=50;
                    Sleep(150);}
                    break;

             case 2:
                 while(true)
                    {
                     game.pollEvent(event);

                     if(event.type==Event::Closed)
                        {
                            game.close();
                            break;
                                }
                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                        {
                        Sleep(150);
                        break;}

                        game.clear(Color::Black);
                        game.draw(mn_sprite);
                        for(int i=0;i<4;i++)game.draw(credits[i]);

                        game.display();

                    }

               Sleep(150);
                    break;
             case 3:game.close();
                    break;

     }
     }
    view.reset(FloatRect(0,0,1600,900));
    game.clear(Color::Black);
    game.draw(mn_sprite);
    menu.draw(&game);
    game.display();
    if(!game.isOpen())break;
 }



 cout<<"wszytko OK"<<endl;
    return 0;
}
