#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>

typedef struct
{
	int clicdroit;
	int clicgauche;
	int x, y;
	int quit;
	int touche[300];
}EVENT;

typedef struct
{
    int i, tmp, o;
    int n[20];
    int tmpo;
    int c;
}Animation;

typedef struct
{
    SDL_Rect position;
    SDL_Surface *image;
    int etat;
    Animation anim;
}Personnage;

typedef struct
{
    int x;
    int y;
}taille;

typedef struct
{
    char nomPerso[100];
    char posSprite[100];
    char persoFace[100];


}characters;

void Evenement(EVENT *evenement);
const int FLIP_VERTICAL = 1;
const int FLIP_HORIZONTAL = 2;
SDL_Surface * flip_surface( SDL_Surface *surface,SDL_Surface * flipped, int flags );
void init(characters * chara);
