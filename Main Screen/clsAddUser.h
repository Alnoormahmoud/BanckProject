#pragma once

#include <iostream>
#include "clsPerson.h"
#include "clsBanckUsers.h"
#include "clsInputValidate.h"
 
class clsAddUser :protected clsScreen
{

    static	int _ReadPermission()
    {
         char _ThisPermission;
        int Permisson = 0;

        cout << "\nDo You Want To Give A Full Permission To This User ? ";
        cin >> _ThisPermission;

        if (_ThisPermission == 'y' || _ThisPermission == 'Y')
        {
            return -1;

        }

        cout << "\n\t\t You Want To Give Prmission To : \n";


        cout << "\nDo You Want To Give Him Accesses To Show List Cleit ? \n";
        cin >> _ThisPermission;
        if (_ThisPermission == 'y' || _ThisPermission == 'Y')
        {

            Permisson += clsBanckUser::enPermission::pListClients;
        }

        cout << "\nDo You Want To Give Him Accesses To Add Cleit ? \n";
        cin >> _ThisPermission;
        if (_ThisPermission == 'y' || _ThisPermission == 'Y')
        {

            Permisson += clsBanckUser::enPermission::pAddNewClient;
        }

        cout << "\nDo You Want To Give Him Accesses To Delete Cleit ? \n";
        cin >> _ThisPermission;
        if (_ThisPermission == 'y' || _ThisPermission == 'Y')
        {

            Permisson += clsBanckUser::enPermission::pDeleteClient;
        }

        cout << "\nDo You Want To Give Him Accesses To UpdateCleit ? \n";
        cin >> _ThisPermission;
        if (_ThisPermission == 'y' || _ThisPermission == 'Y')
        {

            Permisson += clsBanckUser::enPermission::pUpdateClients;
        }

        cout << "\nDo You Want To Give Him Accesses To Find Client ? \n";
        cin >> _ThisPermission;
        if (_ThisPermission == 'y' || _ThisPermission == 'Y')
        {

            Permisson += clsBanckUser::enPermission::pFindClient;
        }
        cout << "\nDo You Want To Give Him Accesses To Transactional Menue ? \n";
        cin >> _ThisPermission;
        if (_ThisPermission == 'y' || _ThisPermission == 'Y')
        {

            Permisson += clsBanckUser::enPermission::pTranactions;
        }

        cout << "\nDo You Want To Give Him Accesses To Manage User Menue ? \n";
        cin >> _ThisPermission;
        if (_ThisPermission == 'y' || _ThisPermission == 'Y')
        {

            Permisson += clsBanckUser::enPermission::pManageUsers;
        }

        cout << "\nDo You Want To Give Him Accesses To Loggins History ? \n";
        cin >> _ThisPermission;
        if (_ThisPermission == 'y' || _ThisPermission == 'Y')
        {

            Permisson += clsBanckUser::enPermission::pShowHistory;
        }

        return Permisson;
    }

    static    void _PrintClient(clsBanckUser Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nUserName    : " << Client.UserName;
        cout << "\nPassword    : " << Client.Password;
        cout << "\nPermission  : " << Client.Permissions;
        cout << "\n___________________\n";

    }

    static void _ReadClientInfo(clsBanckUser& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        
        cout << "\nEnter Password: ";
        Client.Password = clsInputValidate::ReadString();
         
        Client.Permissions = _ReadPermission();

    }
public:



    static   void AddNewUser()
    {
        string Tiltle = "Add User Screen";
        string Sub = "Adding New User";

         _DrawScreenHeader(Tiltle, Sub);
 
        string UserName = "";

        cout << "\nPlease Enter User Name : ";
        UserName = clsInputValidate::ReadString();
        while (clsBanckUser::IsUserExist(UserName))
        {
            cout << "\nUser Name Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsBanckUser NewUser = clsBanckUser::GetAddNewUserObject(UserName);


        _ReadClientInfo(NewUser);

        clsBanckUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsBanckUser::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewUser);
            break;
        }
        case clsBanckUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBanckUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }

};
