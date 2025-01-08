#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsDate.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short FailedLoginCount = 0;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FailedLoginCount++;

                cout << "\nInvlaid Username/Password!\n\n";
                cout << "\nYou have " << 3 - FailedLoginCount << " Trail(s) to login\n\n";

            }

            if (FailedLoginCount == 3)
            {
                cout << "\nYou are looked after 3 failed Trails\n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};

