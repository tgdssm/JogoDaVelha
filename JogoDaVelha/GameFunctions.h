#pragma once
namespace GameFunc
{
	void ShowInitConfiguration();
	void ShowBoard(int GameMatrix[3][3]);
	void MakePlay(int GameMatrix[3][3], int* Player);
	void GameLoop(int GameMatrix[3][3], int* Player, int* LoopControl);
	int CheckGame(int GameMatrix[3][3]);

}