#if !defined(GAME_2D_HPP)
#define GAME_2D_HPP
#include "game.hpp"
class GameState;
class Game2d : public Game
{
private:
    
public:
    Game2d(GameState* gameState);
    ~Game2d();
    void run() override;
};

#endif // GAME_2D_HPP
