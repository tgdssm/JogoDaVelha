class Game
{
	private:
		int GameMatrix[3][3]
		{
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0},
		};
		int Player{ 1 };
		int LoopControl{ 0 };

	public:
		void ShowInitConfiguration();
		void ShowBoard();
		void ShowResult();
		void MakePlay();
		void GameLoop();
		int CheckGame();
		void RunGame();
};