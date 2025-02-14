#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsBanckUsers.h"

class clsUpdateUser : private clsScreen
{

	static	int _ReadPermission()
	{
		char _ThisPermission;
		int Permisson = 0;

		cout << "\n\nDo You Want To Give A Full Permission To This User ? ";
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

			Permisson += clsBanckUser::enPermission::eAll;
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

		return Permisson;
	}

	static void _ReadClientInfo(clsBanckUser & User)
	{
		cout << "\nEnter The New First Name : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter The New Last Name Name : ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter The New Email : ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter The NewPhone : ";
		User.Phone = clsInputValidate::ReadString();
		
		cout << "Enter The New Password: ";
		User.Password =  clsInputValidate::ReadString();

		User.Permissions = _ReadPermission();

	}

	static    void _PrintClient(clsBanckUser User)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " <<User.FirstName;
		cout << "\nLastName    : " <<User.LastName;
		cout << "\nFull Name   : " <<User.FullName();
		cout << "\nEmail       : " <<User.Email;
		cout << "\nPhone       : " <<User.Phone;
		cout << "\nUserName    : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " <<User.Permissions;
		cout << "\n___________________\n";

	}

public:

	static void UpdateUser()
	{
		_DrawScreenHeader("Update User");

		cout << "Please Enter Client User Name : ";

		string UserName = clsInputValidate::ReadString();

		while (!(clsBanckUser::IsUserExist(UserName)))
		{
			cout <<  "UserName You've Entered is Not Valid, Please Enter A Correct One : ";
			UserName = clsInputValidate::ReadString();
		}

		clsBanckUser User1 = clsBanckUser::Find(UserName);
		_PrintClient(User1);
		_ReadClientInfo(User1);

		clsBanckUser::enSaveResults SvSuccessful;
		SvSuccessful = User1.Save();

		switch (SvSuccessful)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError Account Was Not Saved Because It Was Empty ): \n";
			break;

		case clsBankClient::svSucceeded:
			cout << "\nClient Updated Successfully (: \n";
			_PrintClient(User1);

			break;

		}
	}


};

