/**
 * @file		Main.cpp
 * @author		Noam Rodrik
 * @description Program entry point
 */
#include <Core/Loader/GameLoader/GameLoader.h>
#include <Core/Processor/Processor.h>
#include <SDL.h>

using namespace Core;

int main(int argc, char** argv)
{
	// Initialize Simple DirectMedia Library for video rendering, audio, and keyboard events
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;
	SDL_CreateWindowAndRenderer(160 * 3, 144 * 3, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_SetWindowTitle(window, "Rodrik Gameboy Emulator");
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	// Clear screen with White
	SDL_RenderClear(renderer);

	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 160, 144);

	//GameLoader game_loader{"BootROM/cpu_instrs.gb"};
	GameLoader game_loader{"BootROM/tetris.gb"};
	Processor::GetInstance().Run();

	// De-initialize.
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}