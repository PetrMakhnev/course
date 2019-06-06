#include "iostream"
#include "app.h"
using namespace std;

int main(int argc, char** argv) {

	Interface newInterface(1000, 500);

	return newInterface.onExecute();
}