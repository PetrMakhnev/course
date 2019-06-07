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
#include "String/DEC_String.h"

using namespace std;

enum STRING_CLASS_ID {
	STRING_BASE,
	STRING_ID,
	STRING_DEC
};

enum INTERFACE_STATES {
	INTERFACE_START,

	INTERFACE_ENTER_COUNT,
	INTERFACE_ENTER_START_VALUES,

	INTERFACE_TESTING
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

	int state;

	COLOR Colors;

	// элементы интерфейса
	vector <Button_*> Buttons;
	vector <Input_*> Inputs;
	vector <ItemList_*> ItemLists;
	vector <DropDownList*> DropDownLists;
	vector <Label*> Labels;
	vector <TextField*> TextFields;
	//

	// Элементы приложения
	bool ready_fill_classes;

	int count_ready;
	int count_element;
	vector <String*> ptrBaseClass;
	vector <int> type_ptrBaseClasses;

	int nowOperation;

	// Количество элементов каждого класса
	int count_base;
	int count_id;
	int count_dec;

public:
	Interface();
	Interface(short width, short height);
	~Interface();

private:
	void render();
	void onEvent();

	// initialize SDL
	bool init();

	// mouse events prototype
	void mouseButtonDown(SDL_Event* event);
	void mouseButtonUp(SDL_Event* event);
	void mouseMotion(SDL_Event* event);

	// key pressed
	void keyDown(SDL_Event* event);

	//
	void quit();

public:
	int onExecute();

};
