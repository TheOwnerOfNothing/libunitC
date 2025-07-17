#include "libunit.h"

int	abs_launcher(void)
{
	t_unit_test	*testlist;
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "NULL test", &null_test);

	return (0);
}
