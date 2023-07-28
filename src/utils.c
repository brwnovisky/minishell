#include "../headers/minishell.h"

char	*strchr_mod(const char *str, int c)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			if (*str == (char) c)
			{
				str++;
				return ((char *)str);
			}
			str++;
		}
		if ((char) c == '\0' && *str == '\0')
			return ((char *)str);
	}
	return (0);
}

char	*strchr_rev(const char *str, int c)
{
	int			i;
	const char	*temp;

	i = 0;
	temp = str;
	if (str != NULL)
	{
		while (*str != '\0')
		{
			if (*str == (char) c)
				return ((char *)ft_substr(temp, 0, i));
			i++;
			str++;
		}
		if ((char) c == '\0' && *str == '\0')
			return ((char *)str);
	}
	return (0);
}

int	strcmp_mod(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	if (len != ft_strlen(s2))
		return (1);
	while (i < len)
	{
		if (s1[i] != s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		i++;
	}
	return (0);
}

int	ft_isalnum_mod(int c)
{
	int	r;

	r = ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9') || (c == '_' ));
	return (r);
}

char	*ft_strip(char *line, char striped_char)
{
	int		i;
	int		k;
	int		len_line;
	int		len_total;
	char	*temp;

	len_line = ft_strlen(line) - 1;
	i = 0;
	k = len_line;
	while (line[i] && line[i] == striped_char)
		i++;
	while (k >= 0 && line[k] == striped_char)
		k--;
	len_total = k - i + 1;
	temp = ft_calloc(sizeof(char *), len_total);
	temp = ft_substr(line, i, len_total);
	temp[len_total] = '\0';
	return (temp);
}
