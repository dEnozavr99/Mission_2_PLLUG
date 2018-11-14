// ChuVaChi.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <array>

enum playerClass {ROCK, SCISSORS, PAPER, NOTHING};
playerClass selectedClass = NOTHING;


bool doesUserWantToPlay()
{
	bool result = false;
	char answer = ' ';

	while (true)
	{
		std::cout << "Do you want to play?" << std::endl;
		std::cout << "1 - Yes, 0 - No" << std::endl;
		std::cin >> answer;
	
		if (answer == '1')
		{
			result = true;
			break;
		}
		else if (answer == '0')
		{
			std::cout << "Bye bye :(" << std::endl;
			break;
		}

		std::cout << "I don`t understand you" << std::endl;
	}

	return result;
}

playerClass chooseClass()
{
	bool result = false;
	std::string inputClass = "";


	while (true)
	{
		std::cout << "Enter Rock, Scissors or Paper:" << std::endl;
		std::cin >> inputClass;

		if (inputClass == "Rock")
		{
			result = true;
			return ROCK;
			break;
		}
		else if (inputClass == "Scissors")
		{
			result = true;
			return SCISSORS;
			break;
		}
		else if (inputClass == "Paper")
		{
			result = true;
			return PAPER;
			break;
		}
		else if (inputClass == "hui")
		{
			result = false;
			std::cout << "Sam ty hui" << std::endl;
		}

	}
	return NOTHING;
}

void show(bool result)
{
	if (result == true)
	{
		std::cout << "\t You win! ;-)" << std::endl;
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "\t Looser! :-P" << std::endl;
		system("pause");
		system("cls");
	}
}

void beat(playerClass userChoised, playerClass opponent)
{
	bool result = false;

		if ((userChoised == ROCK)&&(opponent == SCISSORS))
		{
			result = true;
			show(result);
		} 
		else if ((userChoised == SCISSORS)&&(opponent == ROCK))
		{
			result = false;
			show(result);
		}


		if ((userChoised == PAPER)&&(opponent == ROCK))
		{
			result = true;
			show(result);
		
		}
		else if ((userChoised == ROCK)&&(opponent == PAPER))
		{
			result = false;
			show(result);
		}

		if ((userChoised == SCISSORS)&&(opponent == PAPER))
		{
			result = true;
			show(result);
		}
		else if ((userChoised == PAPER)&&(opponent == SCISSORS))
		{
			result = false;
			show(result);
		}

		if (userChoised == opponent)
		{
			std::cout << "\t---Draw--" << std::endl;
			system("pause");
			system("cls");
		}

}

playerClass generateOpponent()
{ 
	srand(time(NULL));
	int randomOpponent = rand() % 3;
	switch (randomOpponent)
	{
	case 0:
		{
			return ROCK;
		}
		break;
	case 1:
		{
			return SCISSORS;
		}
		break;
	case 2:
		{
			return PAPER;
		}
		break;
	default:
		{
			return ROCK;
		}
		break;
	}

}

void print (playerClass userChoised, playerClass opponent)
{//вив≥д гравц€
	switch (userChoised)
	{

	case ROCK:
		{
			std::cout << "ROCK";
		}
		break;

	case SCISSORS:
		{
			std::cout << "SCISSORS";
		}
		break;

	case PAPER:
		{
			std::cout << "PAPER";
		}
		break;
	
	}

		std::cout << " VS ";
		//вив≥д противника
		switch (opponent)
	{

	case ROCK:
		{
			std::cout << "ROCK" << std::endl;
		}
		break;

	case SCISSORS:
		{
			std::cout << "SCISSORS" << std::endl;
		}
		break;

	case PAPER:
		{
			std::cout << "PAPER" << std::endl;
		}
		break;
	
	}
}


int main()
{
   while (doesUserWantToPlay())
   {
	   playerClass pl,op;
	   pl = chooseClass();
	   op = generateOpponent();
	   
	   print(pl , op);

	   beat(pl,op);

	   /*std::cout << chooseClass() << std::endl;
	   std::cout << generateOpponent() << std::endl;*/

   }
    return 0;
}

/*\     /       __/\__       ________
   \   /       /      \      @______@
    \ /       |        |     \       \
     O         |      |       |       |
    / \         \    /       /_______/
   @   @         \__/       @_______@*/