/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-06
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-08
 * Description: This Programming Project explores how the unnamed namespace works.
 *				Listed below are snippets from a program to perform input validation for a username and password.
 *				The code to input and validate the username is in a separate file than the code to input and validate the password.
 *************************************************************************/
#include "user.h"
#include "password.h"
#include <iostream>
using namespace std;
using namespace Authenticate;

int main()
{
	inputUserName();
	inputPassword();
	cout << "Your username is " << getUserName() <<
		" and your password is: " << getPassword() << endl;
	return 0;
}
