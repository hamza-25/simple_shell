#include "main.h"

/**
 * _env - Print environment variables
 * @env: Array of environment variables
 *
 * This function prints each element in the `env` array, which represents the
 * environment variables of the program. The elements are printed on separate
 * lines.
 */
void _env_non(int *no_exc)
{
	char **env_ptr = environ;
	*no_exc = 0;
	while (*env_ptr)
	{
		_printf("%s\n", *env_ptr);
		env_ptr++;
	}
}
