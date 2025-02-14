#pragma once
#include<iostream>
#include"clsShowUsers.h"
#include"clsAddUser.h"
#include"clsDeleteUser.h"
#include"clsUpdateUser.h"
#include"clsFindUser.h"
//#include"clsBanckUsers.h"

 class clsManageUserMenue: protected clsScreen
{
 
    enum enManegeUser { ListUser = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, GoBack = 6 };


    static short _ReadManageUserMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 6] ? ";
        short Choice = clsInputValidate::ReadDblNumberBetween(1, 6, "Enter Number between 1 to 6 ? ");
        return Choice;
    }

    static void _ShowListUserScreen()
    {
        clsShowUsers::ShowUsersList();

    }
    
    static void _ShowAddUserScreen()
    {
        clsAddUser::AddNewUser();
    }
    
    static void _ShowDeleteUserScreen()
    {
        clsDeleteUser::DeleteUser();

    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUser::UpdateUser();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUser::ShowFindUserScreen();
    }

    static void _PerfromManageUserMenueOption(enManegeUser ManegeUser)
    {
        switch (ManegeUser)
        {
        case enManegeUser::ListUser:
        {
            system("cls");
            _ShowListUserScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManegeUser::AddUser:
        {
            system("cls");
            _ShowAddUserScreen();
            _GoBackToManageUserMenue();
            break;
        }

        case enManegeUser::DeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUserMenue();
            break;
        } 
        
        case enManegeUser::UpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUserMenue();
            break;
        }

        case enManegeUser::FindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUserMenue();
            break;
        }

        case enManegeUser::GoBack:
        {

        }
        }

    }

    static  void _GoBackToManageUserMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage User Menue...\n";

        system("pause>0");
        ShowManageUserMenue();
    }

public:

    static void ShowManageUserMenue()
    {
        if (!CheackAccessRight(clsBanckUser::enPermission::pManageUsers))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("Manage User Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tManage User Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List User.\n";
        cout << setw(37) << left << "" << "\t[2] Add User\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update Usere.\n";
        cout << setw(37) << left << "" << "\t[5] Find Usere.\n";
        cout << setw(37) << left << "" << "\t[6] Go Back To Main Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromManageUserMenueOption((enManegeUser)_ReadManageUserMenueOption());
    }
};

