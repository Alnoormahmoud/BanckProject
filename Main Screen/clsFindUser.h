#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBanckUsers.h"
#include "clsInputValidate.h"

class clsFindUser :public clsScreen
{

private:
    static void _PrintClient(clsBanckUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " <<User.FirstName;
        cout << "\nLastName    : " <<User.LastName;
        cout << "\nFull Name   : " <<User.FullName();
        cout << "\nEmail       : " <<User.Email;
        cout << "\nPhone       : " <<User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " <<User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen()
    {

        _DrawScreenHeader("Find User Screen");

        string UserName;
        cout << "\nPlease Enter UserName : ";
        UserName = clsInputValidate::ReadString();
        while (!clsBanckUser::IsUserExist(UserName))
        {
            cout << "\nUserName is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsBanckUser User1 = clsBanckUser::Find(UserName);

        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintClient(User1);

    }

};

