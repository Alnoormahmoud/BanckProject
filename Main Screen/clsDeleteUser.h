#pragma once
#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsBanckUsers.h"
#include "clsInputValidate.h"


class  clsDeleteUser :protected clsScreen
{
    static    void _PrintClient(clsBanckUser User)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " <<User.FirstName;
        cout << "\nLastName    : " <<User.LastName;
        cout << "\nFull Name   : " <<User.FullName();
        cout << "\nEmail       : " <<User.Email;
        cout << "\nPhone       : " <<User.Phone;
        cout << "\nUser Name   : " <<User.UserName;
        cout << "\nPassword    : " <<User.Password;
        cout << "\nPermission  : " <<User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void DeleteUser()
    {
        string Tiltle = "Delete User Screen";
        string Sub = "Deleting User";

        _DrawScreenHeader(Tiltle, Sub);
        string UserName = "";

        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();
        while (!clsBanckUser::IsUserExist(UserName))
        {
            cout << "\nUser Nameis not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsBanckUser Usre1 = clsBanckUser::Find(UserName);
        _PrintClient(Usre1);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Usre1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintClient(Usre1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }

};
