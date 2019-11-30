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
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !c)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + c + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
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
	int	sign;
	int	n;
	int 	basesize;
	
	i = 0;
	base_size = ft_strlen(base);
	while ((n /= base) >= 1)
		i++;
	i += 1;
	if (!(str = (char *)ft_calloc(sizeof(char), (i + 1))))
		return (NULL);
	while (i--)
	{
		str[i + sign] = base[(n % base < 10) ? n % base + '0' : n % base + 'a' - 10];
		n /= base;
	}
	return (str);
}
