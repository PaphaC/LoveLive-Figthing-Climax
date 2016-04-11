#include "structures.h"
#ifdef __MINGW32__
#undef main
#endif

using namespace std;

void setVisages(characters *chara,SDL_Surface **temp, int charAff1)
{
    cout<<charAff1<<endl;
    for(int i = 0;i<9;i++)
    {
       int j=charAff1-(i-8);
        if(j<0)
        {
            j=8-j;
            //cout<<"MOINS "<<j<<endl;
        }
        else if(j>8)
        {
            j=j-8;
            //cout<<"PLUS "<<j<<endl;
        }
        cout<<i<<" "<<j<<endl;
        temp[i] = IMG_Load(chara[j].persoFace);
    }
}

void affichageVisages(characters * chara, SDL_Surface *ecran, int charAff1, int charAff2)
{
    SDL_Rect pos;
    SDL_Surface * temp[9];
    SDL_Surface * temp2[9];
    SDL_Surface *actChar = IMG_Load("data/actChar");

    setVisages(chara,temp,charAff1);
    /////////////////////////////////////////////
    //1
    pos.x=458;
    pos.y=150;
    SDL_BlitSurface(temp[0],NULL,ecran,&pos);
    //1
    pos.x=458;
    pos.y=520;
    SDL_BlitSurface(temp[1],NULL,ecran,&pos);

    //2
    pos.x=461;
    pos.y=175;
    SDL_BlitSurface(temp[2],NULL,ecran,&pos);

    //2
    pos.x=461;
    pos.y=480;
    SDL_BlitSurface(temp[3],NULL,ecran,&pos);

    //3
    pos.x=464;
    pos.y=210;
    SDL_BlitSurface(temp[4],NULL,ecran,&pos);

    //3
    pos.x=464;
    pos.y=440;
    SDL_BlitSurface(temp[5],NULL,ecran,&pos);

    //4
    pos.x=467;
    pos.y=255;
    SDL_BlitSurface(temp[6],NULL,ecran,&pos);

    //4
    pos.x=467;
    pos.y=385;
    SDL_BlitSurface(temp[7],NULL,ecran,&pos);

    //actual
    pos.x=470;
    pos.y=322;
    SDL_BlitSurface(temp[8],NULL,ecran,&pos);
    ////////////////////////////////////////////////

    setVisages(chara,temp2,charAff2);
    /////////////////////////////////////////////
    //1
    pos.x=682;
    pos.y=150;
    SDL_BlitSurface(temp2[0],NULL,ecran,&pos);
    //1
    pos.x=682;
    pos.y=520;
    SDL_BlitSurface(temp2[1],NULL,ecran,&pos);

    //2
    pos.x=679;
    pos.y=175;
    SDL_BlitSurface(temp2[2],NULL,ecran,&pos);

    //2
    pos.x=679;
    pos.y=480;
    SDL_BlitSurface(temp2[3],NULL,ecran,&pos);

    //3
    pos.x=676;
    pos.y=210;
    SDL_BlitSurface(temp2[4],NULL,ecran,&pos);

    //3
    pos.x=676;
    pos.y=440;
    SDL_BlitSurface(temp2[5],NULL,ecran,&pos);

    //4
    pos.x=673;
    pos.y=255;
    SDL_BlitSurface(temp2[6],NULL,ecran,&pos);

    //4
    pos.x=673;
    pos.y=385;
    SDL_BlitSurface(temp2[7],NULL,ecran,&pos);

    //actual
    pos.x=670;
    pos.y=322;
    SDL_BlitSurface(temp2[8],NULL,ecran,&pos);
    ////////////////////////////////////////////////

    //Point d'interrogation
    pos.x= 615;
    pos.y=327;
    SDL_BlitSurface(actChar,NULL, ecran,&pos);

    SDL_Flip(ecran);

    for(int i=0; i<9;i++)
    {
        SDL_FreeSurface(temp[i]);
        SDL_FreeSurface(temp2[i]);
    }

    SDL_FreeSurface(actChar);
}

int main(int argc, char *argv[])
{
    EVENT event;
    SDL_Rect pos;
    SDL_Surface *ecran = NULL;

    SDL_Surface *background = IMG_Load("data/splashscreen");
    SDL_Surface *barNom = IMG_Load("data/nameBar");
    SDL_Surface *barChar = IMG_Load("data/charBar");
    SDL_Surface *nomP1;
    SDL_Surface *nomP2= NULL;

    int cursorP1=0, cursorP2=0;
    SDL_Surface *charAff1P= NULL;
    SDL_Surface *charAff2P = NULL;
    SDL_Surface *flipped = NULL;
    characters chara[9];


    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();

    SDL_Color couleurNoire = {0, 0, 0};
    TTF_Font *police = TTF_OpenFont("data/tahoma.ttf",65);

    init(chara);

    ecran = SDL_SetVideoMode(1280, 720, 24, SDL_HWSURFACE | SDL_DOUBLEBUF);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

	Mix_Music *musique= Mix_LoadMUS("data/bgm/charselect.ogg");
	Mix_Chunk *sfx= Mix_LoadWAV( "data/bgm/notify.wav" );

    Mix_PlayMusic(musique, -1);

    SDL_WM_SetIcon(IMG_Load("data/icon"), NULL);
	SDL_WM_SetCaption("LoveLive Fighting Climax", NULL);

    while(event.quit!=1)
    {
        Evenement(&event);

        charAff1P  = IMG_Load(chara[cursorP1].posSprite);
        charAff2P = IMG_Load(chara[cursorP2].posSprite);
        flipped = flip_surface(charAff2P,flipped,2);

        if(event.touche[SDLK_UP]==1)
        {
            cursorP1--;
            if(cursorP1 < 0)
                cursorP1=8;
            Mix_PlayChannel( 1, sfx, 0 );
        }
        else if(event.touche[SDLK_DOWN]==1)
        {
            cursorP1++;
            if(cursorP1 > 8)
                cursorP1=0;
            Mix_PlayChannel( 1, sfx, 0 );
        }
        else if(event.touche[SDLK_8]==1)
        {
            cursorP2--;
            if(cursorP2 < 0)
                cursorP2=8;
            Mix_PlayChannel( 1, sfx, 0 );
        }
        else if(event.touche[SDLK_5]==1)
        {
            cursorP2++;
            if(cursorP2 > 8)
                cursorP2=0;
            Mix_PlayChannel( 1, sfx, 0 );
        }

        SDL_BlitSurface(background,NULL,ecran,NULL);

        //Blitz char1
        pos.y=50;
        pos.x=-70;
        SDL_BlitSurface(charAff1P,NULL, ecran, &pos);

        //Blitz char2
        pos.x = 700;
        SDL_BlitSurface(flipped,NULL, ecran, &pos);

        pos.y=50;
        pos.x=0;
        SDL_BlitSurface(barChar,NULL,ecran,&pos);

        //Blitz barre Nom
        pos.x=0;
        pos.y=620;
        SDL_BlitSurface(barNom,NULL, ecran,&pos);


        pos.x= 110;
        pos.y= 635;
        nomP1= TTF_RenderText_Blended(police,chara[cursorP1].nomPerso, couleurNoire);
        SDL_BlitSurface(nomP1,NULL,ecran,&pos);

        pos.x= 950;
        pos.y= 635;
        nomP1= TTF_RenderText_Blended(police,chara[cursorP2].nomPerso, couleurNoire);
        SDL_BlitSurface(nomP1,NULL,ecran,&pos);

       affichageVisages(chara,ecran,cursorP1,cursorP2);



        ///////////////////////////////////////////
        SDL_Flip(ecran);
        SDL_FreeSurface(charAff1P);
        SDL_FreeSurface(charAff2P);
        SDL_FreeSurface(flipped);
        SDL_FreeSurface(nomP1);
        SDL_Delay(33);


    }


    return 0;
}
