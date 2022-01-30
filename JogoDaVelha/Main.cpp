#include<iostream>
#include "GameFunctions.h";

int main()
{
	setlocale(LC_ALL, "portuguese");

	int GameMatrix[3][3]
	{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
	};
	int Player{ 1 };
	int LoopControl{ 0 };

	GameFunc::ShowInitConfiguration();
	GameFunc::GameLoop(GameMatrix, &Player, &LoopControl);
	GameFunc::ShowBoard(GameMatrix);
	if (LoopControl == 3) std::cout << "Jogador 1 venceu\n";
	else if (LoopControl == -3) std::cout << "Jogador 2 venceu\n";
	else if (LoopControl == 1) std::cout << "Empate\n";



	system("PAUSE");
	return 0;
}