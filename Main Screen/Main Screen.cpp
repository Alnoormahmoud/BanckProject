#include <iostream>
#include "clsLoginScreen.h"

int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowloggInScreen())
        {
            break;
        }
    }
     return 0;
}