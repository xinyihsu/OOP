#include "Header.h"

using namespace std;
void RunCommandFile(string, string);
void RunCommandInput(void);
void execute(void);

//create a class of MineSweeper
MineSweeper myMineSweeper;
ifstream inputFile;


int main(int argc, char* argv[])
{

	if (argc == 0)
	{
		cout << "arg error!" << endl;
		return 0;
	}
	else if (argc == 1)
	{
		//return RunGUI(argc, argv);
	}
	else if (string(argv[1]) == string("CommandFile") && argc == 4)
	{
		RunCommandFile(argv[2], argv[3]);
	}
	else if (string(argv[1]) == string("CommandInput") && argc == 2)
	{
		RunCommandInput();
	}
	else if (string(argv[1]) == string("GUI") && argc == 2)
	{
		//return RunGUI(argc, argv);
	}
	else
	{
		cout << "arg error!" << endl;
		return 0;
	}
}

void RunCommandFile(string commandFile, string outputFileName)
{
	ofstream outputFile(outputFileName);
	cout.rdbuf(outputFile.rdbuf());
	inputFile.open(commandFile);
	execute();
	outputFile.close();
}

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

		while (stringstream >> temp)
		{
			inputString.push_back(temp);
		}

		stringstream.clear();
		stringstream.str("");


		if (inputString[1] == "Load")
		{
			myMineSweeper.Load(inputString);
		}
		else if (inputString[1] == "StartGame")
		{
			myMineSweeper.StartGame();
		}
		else if (inputString[1] == "Print")
		{
			myMineSweeper.Print(inputString);
		}
		else if (inputString[1] == "LeftClick")
		{
			myMineSweeper.LeftClick(inputString);
		}
		else if (inputString[1] == "RightClick")
		{
			myMineSweeper.RightClick(inputString);
		}
		else if (inputString[1] == "Replay")
		{
			myMineSweeper.Replay();
		}
		else if (inputString[1] == "Quit") //eachLine
		{
			myMineSweeper.Quit(); //break;
		}
		else
		{
			cout << "<" << inputString[0] << "> : Failed" << endl;
		}

		getline(cin, eachLine);
	}
}

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

		while (stringstream >> temp)
		{
			inputString.push_back(temp);
		}

		stringstream.clear();
		stringstream.str("");


		if (inputString[1] == "Load")
		{
			myMineSweeper.Load(inputString);
		}
		else if (inputString[1] == "StartGame")
		{
			myMineSweeper.StartGame();
		}
		else if (inputString[1] == "Print")
		{
			myMineSweeper.Print(inputString);
		}
		else if (inputString[1] == "LeftClick")
		{
			myMineSweeper.LeftClick(inputString);
		}
		else if (inputString[1] == "RightClick")
		{
			myMineSweeper.RightClick(inputString);
		}
		else if (inputString[1] == "Replay")
		{
			myMineSweeper.Replay();
		}
		else if (inputString[1] == "Quit") //eachLine
		{
			myMineSweeper.Quit(); //break;
		}
		else
		{
			cout << "<" << inputString[0] << "> : Failed" << endl;
		}

		getline(inputFile, eachLine);
	}
	inputFile.close();
}
