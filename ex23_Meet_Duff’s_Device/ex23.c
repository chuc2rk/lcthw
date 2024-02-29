#include <stdio.h>
#include <string.h>
#include "dbg.h"


int valid_copy(char* data, int count, char expects)
{
	int = 0;
	for (i = 0; i < count; i++) {
		if (data[i] != expects) {
			log_err("[%d] %c != %c", i, data[i], expects);
			return 0;
		}
	}
	
	return 1;
}

int main(int argc, char* argv[])
{
	char from[1000] = {'a'};
	char to[1000] = {'c'};
	
	//set up the from to have some stuff
	memset(from, 'x', 1000);
	//set it to a failure mode
	memset(to, 'y', 1000);
	check(valid_copy(to, 1000, 'y'), "Not initialized right.");
	
	
}