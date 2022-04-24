// ? header files
#include "game.hpp"
#include "Bhuruz.hpp"
#include "drawing.hpp"
//* The images that will be used either for assets or background
SDL_Renderer *Drawing::gRenderer = NULL;
SDL_Texture *Drawing::startAssets = NULL;
SDL_Texture *Drawing::gameAssets = NULL;
SDL_Texture *Drawing::levelOne = NULL;
SDL_Texture *Drawing::levelTwo = NULL;
SDL_Texture *Drawing::levelThree = NULL;

//* The music that will be played
Mix_Music *gMusic = NULL;

//* The sound effects that will be used
Mix_Chunk *Drawing::gHealth = NULL;
Mix_Chunk *Drawing::gCrash = NULL;
Mix_Chunk *Drawing::gExplode = NULL;
Mix_Chunk *Drawing::gGameOver = NULL;

/**
 * ? @brief init()
 * * Initializing SDL
 * * Setting texture filtering to linear
 * * creating window and creating its renderer, whose colours are defined
 * * Initialize PNG loader and SDL mixer
 *
 * ! return
 * * boolean - success is by default true and is assigned false when any of the above desired functions doesnt work properly
 */
bool Game::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		gWindow = SDL_CreateWindow("Bhuruz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			Drawing::gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (Drawing::gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}
/**
 * ? @brief loadMedia()
 * * this function loads all the png files for assets, backgrounds (each for a level)
 * * loads all images into SDL_texture which were initialized in drawing class
 *
 * * loads background music and sound effects for crash, game over,explosion (bomb) and health(health obstacle)
 * * all these wav files our loaded using SDL mixer which were initialized in drawing class
 *
 * ! return
 * * boolean - success is by default true and is assigned false when any of the above desired functions doesnt work properly
 */
bool Game::loadMedia()
{
	// Loading success flag
	bool success = true;

	Drawing::startAssets = loadTexture("assets/start-assets.png");
	Drawing::gameAssets = loadTexture("assets/game-assets.png");

	Drawing::levelOne = loadTexture("assets/level1.png");
	Drawing::levelTwo = loadTexture("assets/level2.png");
	Drawing::levelThree = loadTexture("assets/level3.png");

	gTexture = loadTexture("assets/background.png");

	// gMusic = Mix_LoadMUS("sounds/beat.wav");
	gMusic = Mix_LoadMUS("sounds/RickRoll.wav");

	Drawing::gCrash = Mix_LoadWAV("sounds/crash.wav");
	Drawing::gHealth = Mix_LoadWAV("sounds/health.wav");
	Drawing::gExplode = Mix_LoadWAV("sounds/explode.wav");
	Drawing::gGameOver = Mix_LoadWAV("sounds/gameOver.wav");

	if (Drawing::startAssets == NULL || gTexture == NULL || gMusic == NULL || Drawing::gCrash == NULL || Drawing::gHealth == NULL || Drawing::gExplode == NULL || Drawing::gGameOver == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}
/**
 * ? @brief close()
 * * using SDL's destroy function all images are destroyed and are assigned to null
 *
 * * similarly, all sound effects are destroyed by using Mix free function
 * * all sound effects which were initilized in drawing class are assigned to NULL
 *
 * * destroying renderer and window and assigning them to NULL
 *
 * * Quit SDL subsystems
 */
void Game::close()
{
	SDL_DestroyTexture(Drawing::startAssets);
	Drawing::startAssets = NULL;

	SDL_DestroyTexture(Drawing::gameAssets);
	Drawing::gameAssets = NULL;

	SDL_DestroyTexture(Drawing::levelOne);
	Drawing::levelOne = NULL;

	SDL_DestroyTexture(Drawing::levelTwo);
	Drawing::levelTwo = NULL;

	SDL_DestroyTexture(Drawing::levelThree);
	Drawing::levelThree = NULL;
	SDL_DestroyTexture(gTexture);

	Mix_FreeChunk(Drawing::gHealth);
	Mix_FreeChunk(Drawing::gCrash);
	Mix_FreeChunk(Drawing::gExplode);
	Mix_FreeChunk(Drawing::gGameOver);
	Drawing::gHealth = NULL;
	Drawing::gCrash = NULL;
	Drawing::gExplode = NULL;
	Drawing::gGameOver = NULL;

	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	SDL_DestroyRenderer(Drawing::gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	Drawing::gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
}
/**
 * ? @brief loadTexture()
 * * loading image at specified path using SDL surface
 * * creating texture from  the surface pixels
 * * getting rid of old loaded surface
 *
 * ? @param
 *
 * * string - path of the image which has to be loaded using surface
 *
 * ! return
 * * SDL_Texture* - a pointing reference to the final texture
 */
SDL_Texture *Game::loadTexture(std::string path)
{
	SDL_Texture *newTexture = NULL;

	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(Drawing::gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
/**
 * ? @brief run()
 * * takes inputs from the user using keyboard keys and mouse
 * * using SDL event the input is processed, if its a mose click bhuruz's class click handler function is called
 * * if the input is escape key, the game is quit
 * * if right or left arrow keys are pressed, bhuruz class make move function is called
 *
 * * the background music is played continously using a counter
 *
 * * remove everything from renderer
 * * Draws background to renderer and displays the updated renderer
 * * causes sdl engine to delay for specified miliseconds that is 100 in our case
 *
 */
void Game::run()
{
	bool quit = false;
	int counter = 5;
	SDL_Event e;

	Bhuruz bhuruz;
	bhuruz.init();

	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				bhuruz.onClickHandler(xMouse, yMouse);
			}
			else
			{
				if (e.key.keysym.sym == SDLK_RIGHT)
				{
					bhuruz.makeMove("RIGHT");
				}
				if (e.key.keysym.sym == SDLK_LEFT)
				{
					bhuruz.makeMove("LEFT");
				}
			}
			if (Mix_PlayingMusic() == 0)
			{
				Mix_PlayMusic(gMusic, 20);
			}
			else
			{
				if (Mix_PausedMusic() == 1)
				{
					counter--;
					if (!counter)
					{
						Mix_ResumeMusic();
						counter = 10;
					}
				}
			}
		}

		SDL_RenderClear(Drawing::gRenderer);
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);
		//***********************draw & create the objects here********************

		bhuruz.createObstacles();
		bhuruz.drawObjects();

		//****************************************************************
		SDL_RenderPresent(Drawing::gRenderer);

		SDL_Delay(100);
	}
}
