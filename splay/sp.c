#include <SDL2/SDL.h>
#include <signal.h>

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_NOPARACHUTE);
	signal(SIGINT, SIG_DFL);
	SDL_AudioSpec wavspec;
	Uint32 wavlen;
	Uint8 *wavbuf;
	SDL_LoadWAV(argv[1], &wavspec, &wavbuf, &wavlen);
	SDL_AudioDeviceID devid = SDL_OpenAudioDevice(NULL, 0, &wavspec, NULL, 0);
	int succ = SDL_QueueAudio(devid, wavbuf, wavlen);
	SDL_PauseAudioDevice(devid, 0);
	SDL_Delay(wavlen);
	SDL_CloseAudioDevice(devid);
	SDL_FreeWAV(wavbuf);
	SDL_Quit();

	return 0;
}
