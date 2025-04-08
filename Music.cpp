#include "Music.h"


void Music::Init(){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

Mix_Music* Music::LoadMusic(const char *FileName){
    return Mix_LoadMUS(FileName);
}
