#pragma once
#include <iostream>
#include "clsBanckUsers.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsMainscreen.h"
#include "global.h"
#include "clsDate.h"

class clsPrintTime
{

public:

	static void HelloMessage()
	{
		int Time = clsDate::GetSystemHour();

		if (Time > 15)
		{
			cout << "Good Evening ";
		}
		else if (Time > 11 && Time <= 15)
		{
			cout << "Good Aftrnoon ";
		}
		else
		{
			cout << "Good Morning ";
		}

	}
};

