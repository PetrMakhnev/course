#include "iostream"
#include "app.h"
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Rus");

	Interface newInterface(1200, 500);

	return newInterface.onExecute();
}