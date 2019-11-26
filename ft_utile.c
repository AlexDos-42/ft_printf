# include "ft_printf.h"

char	*ft_strdup_char(char c)
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

char	*ft_itoa_base(int nbr, int base)
{
	char	*str;
	int		i;
	int		sign;
	int		n;

	i = 0;
	sign = (nbr < 0 && base == 10) ? 1 : 0;
	n = (nbr < 0) ? -nbr : nbr;
	while ((n /= base) >= 1)
		i++;
	i += 1;
	n = (nbr < 0) ? -nbr : nbr;
	if (!(str = (char *)ft_calloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i--)
	{
		str[i + sign] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	(sign) ? str[0] = '-' : 0;
	return (str);
}
