#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


#define MAX_NUMBER_OF_ITEMS 4

class Menu{
public:
	Menu(float width, float height);
	~Menu()=default;

	void draw(RenderWindow* window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void Setmenucase(string txt1,string txt2,string txt3,string txt4);

private:
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];

};
