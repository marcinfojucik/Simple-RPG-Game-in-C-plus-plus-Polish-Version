// MECHANIKA GRY !!!
#include "gra.h"

using namespace std;

int main ()
{
	srand(time(NULL));
	menu();
	while(!player_smierc)
	{
		gra();
	}
	return 0;
}
