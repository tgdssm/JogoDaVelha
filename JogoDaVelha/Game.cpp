#include<iostream>
#include "Game.h"

void Game::ShowInitConfiguration()
{
	std::cout << "*** Bem-vindo ao jogo da velha! ***" << std::endl;
	std::cout << "Configura??o inicial" << std::endl;
	std::cout << "    0   1   2\n";
	std::cout << "0     |   |  ";
	std::cout << "\n   ---+---+---\n";
	std::cout << "1     |   |  ";
	std::cout << "\n   ---+---+---\n";
	std::cout << "2     |   |  \n\n";
}

void Game::ShowBoard()
{
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{

			if (j == 2)
			{
				if (GameMatrix[i][j] == 1) std::cout << " X ";
				else if (GameMatrix[i][j] == -1) std::cout << " O ";
				else std::cout << "   ";
			}
			else
			{
				if (GameMatrix[i][j] == 1) std::cout << " X " << "|";
				else if (GameMatrix[i][j] == -1) std::cout << " O " << "|";
				else std::cout << "   " << "|";
			}


		}
		if (i < 2)
		{
			std::cout << "\n---+---+---";
		}
		std::cout << "\n";
	}
}

void Game::ShowResult()
{
	if (LoopControl == 3) std::cout << "Jogador 1 venceu\n";
	else if (LoopControl == -3) std::cout << "Jogador 2 venceu\n";
	else if (LoopControl == 1) std::cout << "Empate\n";
}

void Game::MakePlay()
{
	int SelectLine;
	int SelectColumn;
	if (Player == 1) std::cout << "Jogador 1\n";
	else std::cout << "Jogador 2\n";
	std::cout << "Selecione uma linha: ";
	std::cin >> SelectLine;
	std::cout << "Selecione uma coluna: ";
	std::cin >> SelectColumn;
	while (GameMatrix[SelectLine][SelectColumn] != 0)
	{
		std::cout << "Essa posi??o j? est? em uso.\n";
		std::cout << "Selecione uma nova linha: ";
		std::cin >> SelectLine;
		std::cout << "Selecione uma nova coluna: ";
		std::cin >> SelectColumn;
	}
	if (Player == 1) GameMatrix[SelectLine][SelectColumn] = 1;
	if (Player == 2) GameMatrix[SelectLine][SelectColumn] = -1;
}

void Game::GameLoop()
{

	while (LoopControl != 3 && LoopControl != -3 && LoopControl != 1)
	{
		ShowBoard();
		std::cout << "Escolha uma posi??o: ";
		MakePlay();
		if (Player == 1) Player = 2;
		else Player = 1;
		LoopControl = CheckGame();
		std::cout << LoopControl << std::endl;
	}
}

int Game::CheckGame()
{
	int ResultGame{ 0 };
	int TiedGame{ 0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// diagonals
			ResultGame = GameMatrix[0][0] + GameMatrix[1][1] + GameMatrix[2][2];
			if (ResultGame == -3 || ResultGame == 3) return ResultGame;
			ResultGame = GameMatrix[0][2] + GameMatrix[1][1] + GameMatrix[2][0];
			if (ResultGame == -3 || ResultGame == 3) return ResultGame;

			// columns
			ResultGame = GameMatrix[0][j] + GameMatrix[1][j] + GameMatrix[2][j];
			if (ResultGame == -3 || ResultGame == 3) return ResultGame;

			// rows
			ResultGame = GameMatrix[i][0] + GameMatrix[i][1] + GameMatrix[i][2];
			if (ResultGame == -3 || ResultGame == 3) return ResultGame;

			// tied
			if (GameMatrix[i][j] != 0)
			{
				TiedGame++;
				if (TiedGame == 9)
				{
					return 1;
				}
				else ResultGame = 0;
			}
			else ResultGame = 0;
		}
	}

	return ResultGame;
}

void Game::RunGame()
{
	ShowInitConfiguration();
	GameLoop();
	ShowBoard();
	ShowResult();
}