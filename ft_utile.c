# include "ft_printf.h"

char	*ft_strjoin_char(char const *s1, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc((ft_strlen(s1) + (c != 0) + 1) * sizeof(char))))
		return (NULL);
	while (s1 && *s1)
		new[i++] = *s1++;
	if (c)
		new[i++] = c;
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char c)
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
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
