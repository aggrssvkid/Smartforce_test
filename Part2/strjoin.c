#include <stdlib.h>
#include <string.h>

static char	*copys1(char *runman, char *runjoin)
{
	while (*runman != '\0')
	{
		*runjoin = *runman;
		runjoin++;
		runman++;
	}
	return (runjoin);
}

char	*strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*runman;
	char	*runjoin;

	if (s1 == 0 || s2 == 0)
		return (0);
	runman = (char *) s1;
	join = malloc((strlen(s1) + strlen(s2) + 1) * 1);
	if (join == 0)
		return (0);
	runjoin = join;
	runjoin = copys1(runman, runjoin);
	runman = (char *) s2;
	while (*runman != '\0')
	{
		*runjoin = *runman;
		runjoin++;
		runman++;
	}
	*runjoin = '\0';
	return (join);
}
