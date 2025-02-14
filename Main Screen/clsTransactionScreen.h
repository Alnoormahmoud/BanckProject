#pragma once
#include<iostream>
#include"clsMainscreen.h"
#include"clsDeposit.h"
#include"clsWithdrow.h"
#include"clsTotalBalances.h"
#include"clsTransfare.h"
#include"clsTransfaresHistory.h"

 

class clsTransactionScreen : protected clsScreen
{
    enum enTransaction { Deposit = 1, Withdrow = 2, TotalBalances = 3 ,Transfare = 4, TransfaresHistory=5, GoBack=6};


    static short _ReadTransactionMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 6] ? ";
        short Choice = clsInputValidate::ReadDblNumberBetween(1, 6, "Enter Number between 1 to 6 ? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDeposit::Deposit();
    }

    static void _ShowWithdrowScreen()
    {
        clsWithdrow::Withdrow();
    }

    static void _ShowTotalBcreen()
    {
        clsTotalBalances::ShowTotalBalances();

    }

    static void _ShowTransfareBcreen()
    {
        clsTransfare::Transfare();
    }   
    
    static void _ShowTransfaresHistoryBcreen()
    {
        clsTransfaresHistory::ShowTransferLogScreen();
    }

    static void _PerfromTransactionalMenueOption(enTransaction TransMenueOption)
    {
        switch (TransMenueOption)
        {
        case enTransaction::Deposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case enTransaction::Withdrow:
        {
            system("cls");
            _ShowWithdrowScreen();
            _GoBackToTransactionMenue();
            break;
        }

        case enTransaction::TotalBalances:
        {
            system("cls");
            _ShowTotalBcreen();
            _GoBackToTransactionMenue();
            break;
        } 
        
        case enTransaction::Transfare:
        {
            system("cls");
            _ShowTransfareBcreen();
            _GoBackToTransactionMenue();
            break;
        }  
        
        case enTransaction::TransfaresHistory:
        {
            system("cls");
            _ShowTransfaresHistoryBcreen();
            _GoBackToTransactionMenue();
            break;
        }

        case enTransaction::GoBack:
        {
        }
        }

    }

    static  void _GoBackToTransactionMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactional Menue...\n";

        system("pause>0");
        ShowTransactionMenue();
    }

public:

    static void ShowTransactionMenue()
    {
        if (!CheackAccessRight(clsBanckUser::enPermission::pTranactions))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("Transaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransaction Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdrow.\n";
        cout << setw(37) << left << "" << "\t[3] TotalBalances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfare.\n";
        cout << setw(37) << left << "" << "\t[5] Transfares History.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTransactionalMenueOption((enTransaction)_ReadTransactionMenueOption());
    }
};

