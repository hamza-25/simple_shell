#include "main.h"

int my_setenv(const char* name, const char* value, int overwrite)
{
	 size_t name_length;
    size_t value_length;
    size_t total_length;
	char* existing_value;
	char* new_variable;
	int result;

    if (name == NULL || name[0] == '\0') {
        return -1;
    }

    existing_value = getenv(name);
    if (existing_value != NULL && !overwrite) {
        return 0;
    }

    name_length = strlen(name);
    value_length = strlen(value);
    total_length = name_length + value_length + 2;

    new_variable = (char*)malloc(total_length);
    if (new_variable == NULL) {
        return -1;
    }

    snprintf(new_variable, total_length, "%s=%s", name, value);

    result = putenv(new_variable);

    if (result != 0) {
        free(new_variable);
    }

    return result;
}
