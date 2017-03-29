#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

using namespace std;

int main() {


    Screen screen;
    if (screen.init() == false ) {
        cout << "Initialization SDL failed" << endl;
    };


    while(true) {
        if (!screen.processEvents()) {
            break;
        }
    }

    screen.close();


    return 0;
}