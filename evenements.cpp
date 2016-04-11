#include "structures.h"

void Evenement(EVENT *evenement)
{
	evenement->quit=0;
	evenement->clicdroit=0;
	evenement->clicgauche=0;

	SDL_Event event;

    for(int i=0;i<300;i++)
    {
        evenement->touche[i]=0;
    }

	SDL_PollEvent(&event);
	switch(event.type)
    {
		case SDL_QUIT:
			evenement->quit= 1;
		break;

		case SDL_MOUSEBUTTONDOWN:
            switch(event.button.button)
            {
                case SDL_BUTTON_RIGHT:
                    evenement->clicdroit = 1;
                break;
                case SDL_BUTTON_LEFT:
                    evenement->clicgauche = 1;
                break;
            }
		break;
      case SDL_KEYDOWN:
            for(int i=0;i<300;i++)
            {
                if(event.key.keysym.sym==i)
                    evenement->touche[i]=1;
            }
        break;
		case SDL_MOUSEMOTION:
			evenement->x = event.motion.x;
			evenement->y = event.motion.y;
        break;
		/**/
	}
}
