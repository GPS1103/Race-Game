#include <iostream>
#include "menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(Color::Red);
	menu[0].setString("Campaign");
	menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(Color::Black);
	menu[1].setString("Single Race");
	menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(Color::Black);
	menu[2].setString("Credits");
	menu[2].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    menu[3].setFont(font);
	menu[3].setColor(Color::Black);
	menu[3].setString("Exit");
	menu[3].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	selectedItemIndex = 0;
}



void Menu::draw(RenderWindow* window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window->draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(Color::Red);
	}
}

void Menu::Setmenucase(string txt1,string txt2,string txt3,string txt4)
{
    menu[0].setString(txt1);
    menu[1].setString(txt2);
    menu[2].setString(txt3);
    menu[3].setString(txt4);
}
