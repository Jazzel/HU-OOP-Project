// ? header files
#include "game.hpp"
#include "Bhuruz.hpp"
#include "drawing.hpp"

SDL_Renderer *Drawing::gRenderer = NULL;
SDL_Texture *Drawing::startAssets = NULL;
SDL_Texture *Drawing::gameAssets = NULL;
SDL_Texture *Drawing::levelOne = NULL;
SDL_Texture *Drawing::levelTwo = NULL;
SDL_Texture *Drawing::levelThree = NULL;

// The music that will be played
Mix_Music *gMusic = NULL;

// The sound effects that will be used
Mix_Chunk *Drawing::gHealth = NULL;
Mix_Chunk *Drawing::gCrash = NULL;
Mix_Chunk *Drawing::gExplode = NULL;
Mix_Chunk *Drawing::gGameOver = NULL;

/**
 * ? @brief init()
 * * dynamically creates a bomb obstacle using polymorphism
 * * defines the assets's src rect and assigns mover
 *
 * ? @param
 *
 * * SDL_RECT - mover, where the object has to be created
 *
 * ! return
 * * obstacles * - a pointing reference to obstacle which is created
 */
bool Game::init()
{
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("Bhuruz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (Drawing::gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				// Initialize SDL_mixer
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

	// Load music
	// gMusic = Mix_LoadMUS("sounds/beat.wav");
	gMusic = Mix_LoadMUS("sounds/RickRoll.wav");

	// Load sound effects
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

void Game::close()
{
	// Free loaded images
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

	// Free the sound effects
	Mix_FreeChunk(Drawing::gHealth);
	Mix_FreeChunk(Drawing::gCrash);
	Mix_FreeChunk(Drawing::gExplode);
	Mix_FreeChunk(Drawing::gGameOver);
	Drawing::gHealth = NULL;
	Drawing::gCrash = NULL;
	Drawing::gExplode = NULL;
	Drawing::gGameOver = NULL;

	// Free the music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	// Destroy window
	SDL_DestroyRenderer(Drawing::gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	Drawing::gRenderer = NULL;

	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(Drawing::gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
void Game::run()
{
	bool quit = false;
	int counter = 5;
	SDL_Event e;

	Bhuruz bhuruz;
	bhuruz.init();

	while (!quit)
	{
		// Handle events on queue
		while (SDL_PollEvent(&e))
		{
			// User requests quit
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				// this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				// bhuruz.();
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
				// Play the music
				Mix_PlayMusic(gMusic, 20);
			} // If music is being played
			else
			{
				// If the music is paused
				if (Mix_PausedMusic() == 1)
				{
					counter--;
					// Resume the music
					if (!counter)
					{
						Mix_ResumeMusic();
						counter = 10;
					}
				}
			}
		}

		SDL_RenderClear(Drawing::gRenderer);					  // removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL); // Draws background to renderer
		//***********************draw & create the objects here********************

		bhuruz.createObstacles();
		bhuruz.drawObjects();

		//****************************************************************
		SDL_RenderPresent(Drawing::gRenderer); // displays the updated renderer

		SDL_Delay(100); // causes sdl engine to delay for specified miliseconds
	}
}
