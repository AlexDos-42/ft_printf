/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:11:46 by alesanto          #+#    #+#             */
/*   Updated: 2019/12/12 18:43:02 by alesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int i;

	if (!str || !*str || fd < 0)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\324')
			write(fd, "\0", 1);
		else
			write(fd, &str[i], 1);
		i++;
	}
}
