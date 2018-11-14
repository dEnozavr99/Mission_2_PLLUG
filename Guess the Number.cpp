// Guess the Number.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <time.h>

int level = 10;

int selectLevel()
{
	char selectedLevel = '1';
	int difficult = 10;

	std::cout << "\tChoose your level: (enter number of level 1 - 10)" << std::endl;
	std::cout << "Level 1: 1 to 10" << std::endl;
	std::cout << "Level 2: 1 to 20" << std::endl;
	std::cout << "Level 3: 1 to 30" << std::endl;
	std::cout << "Level 4: 1 to 40" << std::endl;
	std::cout << "Level 5: 1 to 50" << std::endl;
	std::cout << "Level 6: 1 to 60" << std::endl;
	std::cout << "Level 7: 1 to 70" << std::endl;
	std::cout << "Level 8: 1 to 80" << std::endl;
	std::cout << "Level 9: 1 to 90" << std::endl;
	std::cout << "Level 10: 1 to 100" << std::endl;

	std::cin >> selectedLevel;

	switch (selectedLevel)
	{
	
	case '1':
		{
			difficult = 10;
		}
		break;

	case '2':
		{
			difficult = 20;
		}
		break;

	case '3':
		{
			difficult = 30;
		}
		break;

	case '4':
		{
			difficult = 40;
		}
		break;

	case '5':
		{
			difficult = 50;
		}
		break;

	case '6':
		{
			difficult = 60;
		}
		break;

	case '7':
		{
			difficult = 70;
		}
		break;

	case '8':
		{
			difficult = 80;
		}
		break;

	case '9':
		{
			difficult = 90;
		}
		break;

	case '10':
		{
			difficult = 100;
		}
		break;

	default:
		{
			std::cout << "I don`t understand you" << std::endl;
		}
		break;

	}
	
	return difficult;
}

int generateNumber (int selectedDifficult)
{
	srand(time(NULL));
	int genNumber = rand() % selectedDifficult + 1;
	//std::cout << genNumber << std::endl;
	return genNumber;
}

int userNumber()
{
	int userEnteredNumber = 1;

	std::cout << "Please, enter your number" << std::endl;
	std::cin >> userEnteredNumber;

	return userEnteredNumber;
}

bool comparison(int userEntered, int generated)
{
	
	bool result = false;
	int attemptions = 0;

	while (true)
	{
		if (userEntered < generated)
		{
			result = true;
			std::cout << "\tGreater!" << std::endl;
			attemptions += 1;
			break;
		}
		else if (userEntered > generated)
		{
			result = true;
			std::cout << "\tLess!" << std::endl;
			attemptions += 1;
			break;
		}
		else if (userEntered == generated)
		{
			result = false;
			std::cout << "\tYou Win!" << std::endl;
			break;
		}
		else if (attemptions == 10)
		{
			result = false;
			std::cout << "\tYou loose!" << std::endl;
			break;
		}

	}
	return result;
}

bool doesUserWantToPlay()
{
	bool result = false;
	char answer = ' ';

	while (true)
	{
		std::cout << "[Level " << level/10 << "] Would you like to play?" << std::endl;
		std::cout << " p - play\n l - select level\n q - quit" << std::endl;
		std::cin >> answer;
	
		if (answer == 'p')
		{
			result = true;
			break;
		}
		else if (answer == 'l')
		{
			level=selectLevel();
		}
		else if (answer == 'q')
		{
			exit;
			break;
		}
		

		std::cout << "I don`t understand you" << std::endl;
	}
	 
	return result;
}


int main()
{
	int oppNum = 0;
	while(doesUserWantToPlay())
	{
		oppNum = generateNumber(level);
		while(comparison(userNumber(),oppNum))
		{
		}
	}


    return 0;
}
