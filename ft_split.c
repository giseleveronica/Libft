#include "libft.h"

static int			ft_isc(char str, char c)
{
	return (str == c);
}

static int		count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isc(*str, c))
			str++;
		if (*str && !ft_isc(*str, c))
		{
			count++;
			while (*str && !ft_isc(*str, c))
				str++;
		}
	}
	return (count);
}

static char	*malloc_word(char *str, char c)
{
	char *word;
	int	x;

	x = 0;
	while (str[x] && !ft_isc(str[x], c))
		x++;
	word = (char *)malloc(sizeof(char) * x + 1);
	x = 0;
	while (str[x] && !ft_isc(str[x], c))
	{
		word[x] = str[x];
		x++;
	}
	word[x] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char **result = (char **)malloc(sizeof(char *) * (count_words((char *)str, c) + 1));

	int x = 0;
	while (*str)
	{
		while (*str && ft_isc(*str, c))
			str++;
		if (*str && !ft_isc(*str, c))
		{
			result[x] = malloc_word((char *)str, c);
			x++;
			while (*str && !ft_isc(*str, c))
				str++;
		}
	}
	result[x] = NULL;
	return (result);
}