 #pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"
#include "clsEncripAndDecript.h"
  
    using namespace std;
    class clsBanckUser : public clsPerson
    {
    private:

        enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
        enMode _Mode;
        string _UserName;
        string _Password;
        int _Permissions;

        bool _MarkedForDelete = false;

        struct stLoginRegisterRecord;

        static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
        {
            stLoginRegisterRecord LoginRegisterRecord;

            vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);

            LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
            LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
            LoginRegisterRecord.Password = clsEncripAndDecript::Decrypt(LoginRegisterDataLine[2],3);
            LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

            return LoginRegisterRecord;

        }

        string _PrepareLogInRecord(string Seperator = "#//#")
        {
            string LoginRecord = "";
            LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
            LoginRecord += _UserName + Seperator;
            LoginRecord += clsEncripAndDecript::Encrypt(Password,3) + Seperator;
            LoginRecord += to_string(Permissions);
            return LoginRecord;
        }

        static clsBanckUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
        {
            vector<string> vUserData;
            vUserData = clsString::Split(Line, Seperator);

            return clsBanckUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
                vUserData[3], vUserData[4], clsEncripAndDecript::Decrypt(vUserData[5],3), stoi(vUserData[6]));

        }

        static string _ConverUserObjectToLine(clsBanckUser User, string Seperator = "#//#")
        {

            string UserRecord = "";
            UserRecord += User.FirstName + Seperator;
            UserRecord += User.LastName + Seperator;
            UserRecord += User.Email + Seperator;
            UserRecord += User.Phone + Seperator;
            UserRecord += User.UserName + Seperator;
            UserRecord += clsEncripAndDecript::Encrypt(User.Password, 3) + Seperator;
            UserRecord += to_string(User.Permissions);

            return UserRecord;

        }

        static  vector <clsBanckUser> _LoadUsersDataFromFile()
        {

            vector <clsBanckUser> vUsers;

            fstream MyFile;
            MyFile.open("Users.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {

                string Line;


                while (getline(MyFile, Line))
                {

                    clsBanckUser User = _ConvertLinetoUserObject(Line);

                    vUsers.push_back(User);
                }

                MyFile.close();

            }

            return vUsers;

        }

        static void _SaveUsersDataToFile(vector <clsBanckUser> vUsers)
        {

            fstream MyFile;
            MyFile.open("Users.txt", ios::out);//overwrite

            string DataLine;

            if (MyFile.is_open())
            {

                for (clsBanckUser U : vUsers)
                {
                    if (U.MarkedForDeleted() == false)
                    {
                        //we only write records that are not marked for delete.  
                        DataLine = _ConverUserObjectToLine(U);
                        MyFile << DataLine << endl;

                    }

                }

                MyFile.close();

            }

        }

        void _Update()
        {
            vector <clsBanckUser> _vUsers;
            _vUsers = _LoadUsersDataFromFile();

            for (clsBanckUser& U : _vUsers)
            {
                if (U.UserName == UserName)
                {
                    U = *this;
                    break;
                }

            }

            _SaveUsersDataToFile(_vUsers);

        }

        void _AddNew()
        {

            _AddDataLineToFile(_ConverUserObjectToLine(*this));
        }

        void _AddDataLineToFile(string  stDataLine)
        {
            fstream MyFile;
            MyFile.open("Users.txt", ios::out | ios::app);

            if (MyFile.is_open())
            {

                MyFile << stDataLine << endl;

                MyFile.close();
            }

        }

        static clsBanckUser _GetEmptyUserObject()
        {
            return clsBanckUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
        }

    public:

        enum enPermission {
            eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
            pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pShowHistory = 128
        };

        struct stLoginRegisterRecord
        {
            string DateTime;
            string UserName;
            string Password;
            int Permissions;

        };

        clsBanckUser(enMode Mode, string FirstName, string LastName,
            string Email, string Phone, string UserName, string Password,
            int Permissions) :
            clsPerson(FirstName, LastName, Email, Phone)

        {
            _Mode = Mode;
            _UserName = UserName;
            _Password = Password;
            _Permissions = Permissions;
        }

        bool IsEmpty()
        {
            return (_Mode == enMode::EmptyMode);
        }

        bool MarkedForDeleted()
        {
            return _MarkedForDelete;
        }

        string GetUserName()
        {
            return _UserName;
        }

        void SetUserName(string UserName)
        {
            _UserName = UserName;
        }

        __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

        void SetPassword(string Password)
        {
            _Password = Password;
        }

        string GetPassword()
        {
            return _Password;
        }
        __declspec(property(get = GetPassword, put = SetPassword)) string Password;

        void SetPermissions(int Permissions)
        {
            _Permissions = Permissions;
        }

        int GetPermissions()
        {
            return _Permissions;
        }
        __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

        static clsBanckUser Find(string UserName)
        {
            fstream MyFile;
            MyFile.open("Users.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    clsBanckUser User = _ConvertLinetoUserObject(Line);
                    if (User.UserName == UserName)
                    {
                        MyFile.close();
                        return User;
                    }
                }

                MyFile.close();

            }

            return _GetEmptyUserObject();
        }

        static clsBanckUser Find(string UserName, string Password)
        {

            fstream MyFile;
            MyFile.open("Users.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    clsBanckUser User = _ConvertLinetoUserObject(Line);
                    if (User.UserName == UserName && User.Password == Password)
                    {
                        MyFile.close();
                        return User;
                    }

                }

                MyFile.close();

            }
            return _GetEmptyUserObject();
        }

        enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

        enSaveResults Save()
        {

            switch (_Mode)
            {
            case enMode::EmptyMode:
            {
                if (IsEmpty())
                {
                    return enSaveResults::svFaildEmptyObject;
                }
            }

            case enMode::UpdateMode:
            {
                 _Update();
                return enSaveResults::svSucceeded;

                break;
            }

            case enMode::AddNewMode:
            {
                //This will add new record to file or database
                if (clsBanckUser::IsUserExist(_UserName))
                {
                    return enSaveResults::svFaildUserExists;
                }
                else
                {
 
                    _AddNew();
                    //We need to set the mode to update after add new
                    _Mode = enMode::UpdateMode;
                    return enSaveResults::svSucceeded;
                }

                break;
            }
            }

        }

        static bool IsUserExist(string UserName)
        {

            clsBanckUser User = clsBanckUser::Find(UserName);
            return (!User.IsEmpty());
        }

        bool Delete()
        {
            vector <clsBanckUser> _vUsers;
            _vUsers = _LoadUsersDataFromFile();

            for (clsBanckUser& U : _vUsers)
            {
                if (U.UserName == _UserName)
                {
                    U._MarkedForDelete = true;
                    break;
                }

            }

            _SaveUsersDataToFile(_vUsers);

            *this = _GetEmptyUserObject();

            return true;

        }

        static clsBanckUser GetAddNewUserObject(string UserName)
        {
            return clsBanckUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
        }

        static vector <clsBanckUser> GetUsersList()
        {
            return _LoadUsersDataFromFile();
        }

        bool CheckAccessPermission(enPermission Permission)
        {
            if (this->Permissions == enPermission::eAll)
                return true;

            if ((Permission & this->Permissions) == Permission)
                return true;
            else
                return false;

        }


        void RegisterLogIn()
        {

            string stDataLine = _PrepareLogInRecord();

            fstream MyFile;
            MyFile.open("Info.txt", ios::out | ios::app);

            if (MyFile.is_open())
            {

                MyFile << stDataLine << endl;

                MyFile.close();
            }

        }

        static  vector <stLoginRegisterRecord> GetLoginRegisterList()
        {
            vector <stLoginRegisterRecord> vLoginRegisterRecord;

            fstream MyFile;
            MyFile.open("Info.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {
                 string Line;

                stLoginRegisterRecord LoginRegisterRecord;

                while (getline(MyFile, Line))
                {

                    LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                    vLoginRegisterRecord.push_back(LoginRegisterRecord);

                }

                MyFile.close();

            }

            return vLoginRegisterRecord;

        }

    };



