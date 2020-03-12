#ifndef UTILITYCLASS_H
#define UTILITYCLASS_H

#if defined(__SWITCH__) || defined(__ANDROID__)
    #include <SDL2/SDL.h>
#else
    #include <SDL.h>
#endif
#include <vector>
#include <string>
#include "GrowingVector.h"

// Script drawing stuff
struct scriptimage {
    int type = 0; // 0 for text, 1 for image, 2 for rect
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    int index = 0;
    std::string text;
    bool center = false;
    int bord = false;
    int sc = 2;
    bool persistent = false;
    int alpha = 0;
    int background = false;
    SDL_BlendMode blend = SDL_BLENDMODE_BLEND;
};

// always return positive modulo result if modulus is positive
template<typename N>
N mod(const N &num, const N &mod) {
    return (num % mod + mod) % mod;
}

int ss_toi(std::string _s);
int relativepos(int original, std::string parsethis);
void relativepos(int* original, std::string parsethis);

bool is_number(const std::string& s);

bool parsebool(std::string parsethis);

growing_vector<std::string> split(const std::string &s, char delim, growing_vector<std::string> &elems);

growing_vector<std::string> split(const std::string &s, char delim);


//helperClass
class UtilityClass
{
public:
    UtilityClass();

    static std::string String(int _v);

    static std::string GCString(growing_vector<SDL_GameControllerButton> buttons);

    std::string twodigits(int t);

    std::string timestring(int t);

    std::string number(int _t);


    static bool intersects( SDL_Rect A, SDL_Rect B );

    void updateglow();

    std::string getmusicname(int num);

    int glow = 0;
    bool freezeglow = false;
    int slowsine = 0;
    int glowdir = 0;
    int globaltemp = 0;
    int temp = 0;
    int temp2 = 0;
    std::string tempstring;
    growing_vector<int> splitseconds;
};

extern UtilityClass help;

#endif /* UTILITYCLASS_H */
