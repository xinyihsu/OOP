#include "Header.h"
#pragma comment(lib,"Winmm.lib")

using namespace std;

void RunCommandFile(string, string);
void RunCommandInput(void);
void execute(void);

//create a class of MineSweeper
MineSweeper myMineSweeper;

ifstream inputFile;

// mode switch
int main(int argc, char* argv[])
{
	PlaySound(TEXT("./music/backround_music.wav"), NULL, SND_FILENAME || SND_ASYNC || SND_LOOP);
	// error
	if (argc == 0)
	{
		cout << "arg error!" << endl;
		return 0;
	}
	// GUI mode
	else if (argc == 1)
	{
		//return RunGUI(argc, argv);
	}
	// Run command file mode
	else if (string(argv[1]) == string("CommandFile") && argc == 4)
	{
		RunCommandFile(argv[2], argv[3]);
	}
	// Run command input mode
	else if (string(argv[1]) == string("CommandInput") && argc == 2)
	{
		RunCommandInput();
	}
	// GUI mode
	else if (string(argv[1]) == string("GUI") && argc == 2)
	{
		//return RunGUI(argc, argv);
	}
	// error
	else
	{
		cout << "arg error!" << endl;
		return 0;
	}

	PlaySound(NULL, NULL, SND_FILENAME);
}

// Intent: To run command file
// Pre: Two string
// Post: void
void RunCommandFile(string commandFile, string outputFileName)
{
	ofstream outputFile(outputFileName);
	cout.rdbuf(outputFile.rdbuf());
	inputFile.open(commandFile);
	execute();
	outputFile.close();
}

// Intent: To run command input
// Pre: void
// Post: void
void RunCommandInput(void)
{
	string eachLine;

	getline(cin, eachLine);

	while (1)
	{
		stringstream stringstream(" ");
		vector<string> inputString;
		string temp;

		stringstream << eachLine;

		inputString.push_back(eachLine);

		// Split spaces
		while (stringstream >> temp)
		{
			inputString.push_back(temp);
		}

		stringstream.clear();
		stringstream.str("");

		// if command is Load
		if (inputString[1] == "Load")
		{
			myMineSweeper.Load(inputString);
		}
		// if command is StartGame
		else if (inputString[1] == "StartGame")
		{
			myMineSweeper.StartGame();
		}
		// if command is Print
		else if (inputString[1] == "Print")
		{
			myMineSweeper.Print(inputString);
		}
		// if command is LeftClick
		else if (inputString[1] == "LeftClick")
		{
			myMineSweeper.LeftClick(inputString);
		}
		// if command is RightClick
		else if (inputString[1] == "RightClick")
		{
			myMineSweeper.RightClick(inputString);
		}
		// if command is Replay
		else if (inputString[1] == "Replay")
		{
			myMineSweeper.Replay();
		}
		// if command is Quit
		else if (inputString[1] == "Quit")
		{
			myMineSweeper.Quit();
		}
		// invalid command
		else
		{
			cout << "<" << inputString[0] << "> : Failed" << endl;
		}

		getline(cin, eachLine);
	}
}

// Intent: execute
// Pre: void
// Post: void
void execute(void)
{
	string eachLine;

	getline(inputFile, eachLine);

	while (1)
	{
		stringstream stringstream(" ");
		vector<string> inputString;
		string temp;

		stringstream << eachLine;

		inputString.push_back(eachLine);

		// Split spaces
		while (stringstream >> temp)
		{
			inputString.push_back(temp);
		}

		stringstream.clear();
		stringstream.str("");

		// if command is Load
		if (inputString[1] == "Load")
		{
			myMineSweeper.Load(inputString);
		}
		// if command is StartGame
		else if (inputString[1] == "StartGame")
		{
			myMineSweeper.StartGame();
		}
		// if command is Print
		else if (inputString[1] == "Print")
		{
			myMineSweeper.Print(inputString);
		}
		// if command is LeftClick
		else if (inputString[1] == "LeftClick")
		{
			myMineSweeper.LeftClick(inputString);
		}
		// if command is RightClick
		else if (inputString[1] == "RightClick")
		{
			myMineSweeper.RightClick(inputString);
		}
		// if command is Replay
		else if (inputString[1] == "Replay")
		{
			myMineSweeper.Replay();
		}
		// if command is Quit
		else if (inputString[1] == "Quit")
		{
			myMineSweeper.Quit();
		}
		// invalid command
		else
		{
			cout << "<" << inputString[0] << "> : Failed" << endl;
		}

		getline(cin, eachLine);
	}

	inputFile.close();
}
