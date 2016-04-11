#include "structures.h"

Uint32 get_pixel32( SDL_Surface *surface, int x, int y )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;

    //Get the requested pixel
    return pixels[ ( y * surface->w ) + x ];
}

void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;

    //Set the pixel
    pixels[ ( y * surface->w ) + x ] = pixel;
}

SDL_Surface * flip_surface( SDL_Surface *surface,SDL_Surface *flipped, int flags )
{

    //If the image is color keyed
    if( surface->flags & SDL_SRCCOLORKEY )
    {
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, 0 );
    }
    //Otherwise
    else
    {
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask );
    }

    //If the surface must be locked
    if( SDL_MUSTLOCK( surface ) )
    {
        //Lock the surface
        SDL_LockSurface( surface );
    }

    //Go through columns
    for( int x = 0, rx = flipped->w - 1; x < flipped->w; x++, rx-- )
    {
        //Go through rows
        for( int y = 0, ry = flipped->h - 1; y < flipped->h; y++, ry-- )
        {
            //Get pixel
            Uint32 pixel = get_pixel32( surface, x, y );

            //Copy pixel
            if( ( flags & FLIP_VERTICAL ) && ( flags & FLIP_HORIZONTAL ) )
            {
                put_pixel32( flipped, rx, ry, pixel );
            }
            else if( flags & FLIP_HORIZONTAL )
            {
                put_pixel32( flipped, rx, y, pixel );
            }
            else if( flags & FLIP_VERTICAL )
            {
                put_pixel32( flipped, x, ry, pixel );
            }
        }
    }

    //Unlock surface
    if( SDL_MUSTLOCK( surface ) )
    {
        SDL_UnlockSurface( surface );
    }

    //Copy color key
    if( surface->flags & SDL_SRCCOLORKEY )
    {
        SDL_SetColorKey( flipped, SDL_RLEACCEL | SDL_SRCCOLORKEY, surface->format->colorkey );
    }

    return flipped;
}

void init(characters * chara)
{
    for(int i =0; i< 9;i++)
    {
        chara[i].nomPerso[0]='\0';
        chara[i].posSprite[0]='\0';
    }

    strcpy(chara[0].nomPerso,"Honoka");
    strcpy(chara[0].posSprite,"data/char/Honoka");
    strcpy(chara[0].persoFace,"data/char/faces/Honoka.jpg");

    strcpy(chara[1].nomPerso,"Kotori");
    strcpy(chara[1].posSprite,"data/char/Kotori");
    strcpy(chara[1].persoFace,"data/char/faces/Kotori.jpg");

    strcpy(chara[2].nomPerso,"Umi");
    strcpy(chara[2].posSprite,"data/char/Umi");
    strcpy(chara[2].persoFace,"data/char/faces/Umi.jpg");

    strcpy(chara[3].nomPerso,"Nico");
    strcpy(chara[3].posSprite,"data/char/Nico");
    strcpy(chara[3].persoFace,"data/char/faces/Nico.jpg");

    strcpy(chara[4].nomPerso,"Eri");
    strcpy(chara[4].posSprite,"data/char/Eri");
    strcpy(chara[4].persoFace,"data/char/faces/Eri.jpg");

    strcpy(chara[5].nomPerso,"Nozomi");
    strcpy(chara[5].posSprite,"data/char/Nozomi");
    strcpy(chara[5].persoFace,"data/char/faces/Nozomi.jpg");

    strcpy(chara[6].nomPerso,"Maki");
    strcpy(chara[6].posSprite,"data/char/Maki");
     strcpy(chara[6].persoFace,"data/char/faces/Maki.jpg");

    strcpy(chara[7].nomPerso,"Hanayo");
    strcpy(chara[7].posSprite,"data/char/Hanayo");
     strcpy(chara[7].persoFace,"data/char/faces/Hanayo.jpg");

    strcpy(chara[8].nomPerso,"Rin");
    strcpy(chara[8].posSprite,"data/char/Rin");
     strcpy(chara[8].persoFace,"data/char/faces/Rin.jpg");


}
