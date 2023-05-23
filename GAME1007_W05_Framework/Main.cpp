#include <SDL_main.h>
#include "Engine.h"
#include "Core.h"

struct Game
{
	// Turn this into a vector of starships
	// Feel free to use additional custom data types like a "struct Sprite"
	Texture* shipTex = nullptr;
	Rect shipRec{ 0.0f, 0.0f, 60.0f, 40.0f };
	float shipSpeed = 100.0f;
};

void Update(Game& game, float dt)
{
	game.shipRec.x += game.shipSpeed * dt;
}

void Render(const Game& game)
{
	DrawTexture(game.shipTex, game.shipRec);
}

int main(int argc, char* argv[])
{
	AppInit(1024, 768);

	Game game;
	game.shipTex = LoadTexture("../Assets/img/enterprise.png");

	// Lab exercise 1 (2.5% of your grade):
	// Make a fleet of starships!
	// Modify the update function to translate a vector of ships in a direction of your choice.
	// Be sure to use *time-based* movement rather than frame-based movement
	// Pass a vector of ships to your render function. Draw them via for-loop

	while (IsRunning())
	{
		Update(game, FrameTime());
		RenderBegin();
		Render(game);
		RenderEnd();
	}

	UnloadTexture(game.shipTex);
	AppExit();
	return 0;
}
