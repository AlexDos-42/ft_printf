# include "ft_printf.h"

char	*ft_cdup(char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!c)
		return (NULL);
	if (!(str = malloc(c + 1 * sizeof(char))))
		return (NULL);
	str[i++] = (unsigned char)c;
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_c(char const *s1, char c)
{
	int		i;
	char	*str;

	i = 0;
	if (!c)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + 2))))
		return (NULL);
	while (s1 && *s1)
	{
		str[i] = *s1++;
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*str;
	int	i;
	int	n;
	int 	basesize;

	i = 0;
	basesize = ft_strlen(base);
	n = nbr;
	while ((n /= basesize) >= 1)
		i++;
	i += 1;
	if (!(str = (char *)ft_calloc(sizeof(char), (i + 1))))
		return (NULL);
	while (i--)
	{
		str[i] = base[nbr % basesize];
		nbr /= basesize;
	}
	return (str);
}
