#include "user.h"

namespace
{
	string username;

	bool isValid()
	{
		int count = 0;
		for (char c : username) {
			if (isalpha(c)) {
				count++;
			}
			else {
				return false;
			}
		}

		if (count == 8) {
			return true;
		}
		return false;
	}
}

namespace Authenticate
{
	/**
	 * Intent: input user name
	 * Pre: void
	 * Post: void
	 */
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}

	/**
	 * Intent: get the user name
	 * Pre: void
	 * Post: the password (string type)
	 */
	string getUserName()
	{
		return username;
	}
}