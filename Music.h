#ifndef Music_H
#define Music_H
#include <SDL_mixer.h>


struct Music{
      void Init();
    Mix_Music* LoadMusic(const char *FileName);
};

#endif
