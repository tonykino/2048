#include "2048.h"

void signal_handler(int signum)
{
	signal_global = 0;
}
