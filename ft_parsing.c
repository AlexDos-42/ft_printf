/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:00:03 by alesanto          #+#    #+#             */
/*   Updated: 2019/12/12 15:39:37 by alesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_flags(char *arg, t_parsing *parsing)
{
	int	i;

	i = 0;
	if (*arg)
	{
		while (arg[i] == '-' || arg[i] == '+'
				|| arg[i] == '0' || arg[i] == ' ' || arg[i] == '#')
		{
			if (arg[i] == '-')
				parsing->flagstiret = -1;
			if (arg[i] == '0' && parsing->flagstiret != -1)
				parsing->flags0 = 1;
			if (parsing->flagstiret == -1)
				parsing->flags0 = 0;
			i++;
		}
	}
	return (i);
}

int			ft_width(char *arg, va_list *va, t_parsing *parsing)
{
	int i;
	int j;

	i = 0;
	if (*arg && ft_isdigit(arg[i]))
	{
		if (parsing->flagstiret == 0)
			parsing->flagstiret = 1;
		parsing->flagstiret *= ft_atoi(arg);
		parsing->flags0 *= parsing->flagstiret;
		while (ft_isdigit(arg[i]))
			i++;
	}
	else if (*arg && arg[i] == '*')
	{
		if (parsing->flagstiret == 0)
			parsing->flagstiret = 1;
		j = parsing->flagstiret > 0 ? 1 : -1;
		parsing->flagstiret *= va_arg(*va, unsigned int);
		if (j == -1 && parsing->flagstiret > 0)
			parsing->flagstiret = -parsing->flagstiret;
		parsing->flags0 *= parsing->flagstiret;
		i++;
	}
	return (i);
}

int			ft_precision(char *arg, va_list *va, t_parsing *parsing)
{
	int i;

	i = 0;
	if (*arg && arg[i] == '.')
	{
		arg++;
		parsing->precision = 0;
		if (*arg && ft_isdigit(arg[i]))
		{
			parsing->precision = ft_atoi(arg);
			while (ft_isdigit(arg[i]))
				i++;
		}
		else if (*arg && arg[i] == '*')
		{
			parsing->precision = va_arg(*va, unsigned int);
			i++;
		}
		i++;
	}
	return (i);
}
