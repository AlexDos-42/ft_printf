# include "ft_printf.h"

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
