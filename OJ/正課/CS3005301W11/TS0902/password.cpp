#include "password.h"

namespace
{
	string password;

	/**
	 * Intent: test if password is valid
	 * Pre: void
	 * Post: bool
	 */
	bool isValid(void)
	{
		int count = 0;

		//count the number of characters
		for (char c : password) {
			count++;
		}

		//the number of characters can not less then eight
		if (count < 8) {
			return false;
		}

		count = 0;

		//count the number of digit
		for (char c : password) {
			if (isdigit(c)) {
				count++;
			}
		}

		//the number of digit can not less then one
		if (count < 1) {
			return false;
		}

		return true;
	}
}

namespace Authenticate
{
	/**
	 * Intent: let user to input password
	 * Pre: void
	 * Post: void
	 */
	void inputPassword(void)
	{
		do {
			cout << "Enter your password (at least 8 characters and at least one non-letter)" << endl;
			cin >> password;
		} while (!isValid());
	}

	/**
	 * Intent: get the password
	 * Pre: void
	 * Post: the password (string type)
	 */
	string getPassword(void)
	{
		return password;
	}
}
