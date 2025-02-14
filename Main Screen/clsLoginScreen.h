#pragma once
#include <iostream>
#include "clsBanckUsers.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsMainscreen.h"
#include "global.h"
#include "clsDate.h"
#include "clsEncripAndDecript.h"

  
class clsLoginScreen  
{
	static bool _LoggIn()
	{
		bool FailedFalied = 0;
		string UserName = "";
		string Password = "";
		int NumberOfTries = 3;

		do
		{
			if (FailedFalied)
			{
				NumberOfTries--;

				if (NumberOfTries == 0)
				{
					cout << "\n\nYour Account Have Been Locked Due To More Tries, Contact The Banck For More.\n\n";
					return false;
				}				 

				cout << "\nInvalid UserName/Password, Please Try Again.";
				cout << "\nYou Have : (" << NumberOfTries << ") More Trail(s) To LogIn. \n";

			}
 
 
 			cout << "\n\nEnter Your UserName : ";
			UserName = clsInputValidate::ReadString();

			cout << "Enter Your Password : ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsBanckUser::Find(UserName, Password);
		
			FailedFalied = CurrentUser.IsEmpty();

		} while (FailedFalied);
	   
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowloggInScreen()
	{
		system("cls");

		clsScreen::_DrawScreenHeader("LoggIn Screen");

		return _LoggIn();
		 
 	}
	
};

