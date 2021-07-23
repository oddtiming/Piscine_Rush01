#include <unistd.h>
#include <stdlib.h>


//returns the pos of *charset at which char c. If not in it, returns (-1)
int	is_charset(char c, char *set)
{
	int	i;

	i = -1;

	while (set[++i])
		if (c == set[i])
			return (i);
	return (-1);
}

char	**ft_split(char *str, char *set)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if str
	}
}

unsigned int	count_strs(char *str, char *set)
{
	int	counter;
	int	i;
	int	is_body;

	i = 0;
	counter = 0;
	is_body = 1;
	while (str[i])
	{
		if (is_charset(str[i], set) && is_body == 1)
		{
			counter++;
			is_body = 0;
		}
		if (is_charset(str[i], set) == -1)
			is_body = 1;
	}
	
}

//Logic:
//you hit a charset, means you started.
//you hit a non-charset, means you have body
//you hit a charset again, means you have one chunk, meaning your return char ** is +1