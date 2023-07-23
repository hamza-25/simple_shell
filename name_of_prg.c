#include "main.h"
/**
 *
 *
*/
char *name_prg(int argc , char *argv[])
{
	char *name = NULL;

	name = argv[argc - 1];
	name++;
	name++;
	return (name);
}
