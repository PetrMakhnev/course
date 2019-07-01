#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "vector"

#include "Color.h"

#include "Elements/button_.h"
#include "Elements/input_.h"
#include "Elements/itemList_.h"
#include "Elements/label.h"
#include "Elements/ListDown.h"
#include "Elements/TextField.h"

#include "String/String.h"
#include "String/ID_String.h"
#include "String/BIN_String.h"

using namespace std;

enum STRING_CLASS_ID {
	STRING_BASE,
	STRING_ID,
	STRING_BIN
};

class Interface {
private:
	bool running;

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	SDL_Texture* texture;

	short screenWidth;
	short screenHeight;


	COLOR Colors;

	// элементы интерфейса
	vector <Button_*> Buttons;
	vector <Input_*> Inputs;
	vector <ItemList_*> ItemLists;
	vector <DropDownList*> DropDownLists;
	vector <Label*> Labels;
	vector <TextField*> TextFields;
	//

	//

	// Ёлементы приложени€
	bool ready_fill_classes;

	int count_ready;
	int count_element;
	vector <String*> ptrBaseClass;
	vector <int> type_ptrBaseClasses;

	int nowOperation;

public:
	Interface();
	Interface(short width, short height);
	~Interface();

private:
	void render();
	void onEvent();

	bool init();
	
	void mouseButtonDown(SDL_Event* event);
	void mouseButtonUp(SDL_Event* event);
	void mouseMotion(SDL_Event* event);

	
	void keyDown(SDL_Event* event);
	void quit();

public:
	int onExecute();

};
