/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:58:26 by alesanto          #+#    #+#             */
/*   Updated: 2019/12/12 17:10:59 by alesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_cdup(int d)
{
	char	*str;
	int		i;
	char	c;

	c = (char)d;
	i = 0;
	if (!c)
	{
		if (!(str = malloc(1 * sizeof(char))))
			return (NULL);
	}
	else
	{
		if (!(str = malloc((2) * sizeof(char))))
			return (NULL);
	}
	if (c)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

char		*ft_strjoin_c(char const *s1, char c)
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

char		*ft_itoa_base(unsigned long long int nbr, char *base)
{
	char						*str;
	int							i;
	unsigned long long int		n;
	int							basesize;

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
