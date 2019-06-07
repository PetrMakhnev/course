#include "iostream"
#include "app.h"
using namespace std;

int main(int argc, char** argv) {

	Interface newInterface(1200, 500);

	return newInterface.onExecute();
}