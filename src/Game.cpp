#include "Game.h"

Game::Game()
{
    player = new Player("o");
    opponent = new Player("x");
    board = new Board;
}

Game::~Game()
{
    delete player;
    delete opponent;
    delete board;
}

void Game::play()
{
	player->init(board);
	opponent->init(board);

	while(1){
    player->decide(board);
    opponent->decide(board);}
}
