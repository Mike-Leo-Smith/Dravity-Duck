#include <time.h>
#include "time.h"


int time_getTicks()
{
	return (((long long)clock()) * 128 / 1000000);
}
