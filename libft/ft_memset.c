/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:11:10 by alesanto          #+#    #+#             */
/*   Updated: 2019/11/06 14:02:30 by alesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	char		*d;
	size_t		i;

	d = (char *)b;
	i = 0;
	while (i < n)
	{
		d[i] = c;
		i++;
	}
	return (d);
}