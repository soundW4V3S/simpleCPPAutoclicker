#include <iostream>
#include <Windows.h>
using namespace std;

bool clickerEnabled = false; // Global variable to track clicker state

void menu()
{
    cout << "Press 'X' to enable, and 'Z' to disable\n";
}

void clicker()
{
    while (true)
    {
        if (GetAsyncKeyState('X')) // If X is pressed, enable clicker
        {
            if (!clickerEnabled) // Check if the state has changed
            {
                clickerEnabled = true;
                cout << "Clicker is turned on!\n";
            }
        }
        else if (GetAsyncKeyState('Z')) // Z disables
        {
            if (clickerEnabled) // Check if the state has changed
            {
                clickerEnabled = false;
                cout << "Clicker is turned off!\n";
            }
        }

        Sleep(1); // Adjust speed here, needed for less cpu use, off = very high CPS, on = halved CPS BUT better cpu usage

        if (clickerEnabled) // if clickerEnabled is true, it will press the left mouse button down and up really fast
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            //Sleep(5); // Adjust speed here
        }
    }
}

int main()
{
    menu();
    clicker();
    return 0;
}

// You can change to one input instead of "x" and "z" which lightens up code
// You can also set bool = !bool to toggle easier + faster
