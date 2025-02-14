#pragma once
#include <iostream>
#include "clsBanckUsers.h"
#include "clsDate.h"
#include "global.h"
  
using namespace std;

class clsScreen
{
public:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
 
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";
 
        cout << "\n\t\t\t\t\t\tDate : " << clsDate::DateToString(clsDate::GetSystemDate())<<endl;
    }


    static bool CheackAccessRight(clsBanckUser::enPermission Permisson)
    {
        if (!CurrentUser.CheckAccessPermission(Permisson))
        {
            cout << "\t\t\t_____________________________________________________________________";
            cout << "\n\t\t\t\t\tAccesses Denied, Contact Your Admin";
            cout << "\n\t\t\t_____________________________________________________________________";
            return false;
        }
        else
        {
            return true;
        }
    }

};

