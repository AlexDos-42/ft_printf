#include "ft_printf.h"

int   ft_flags(char *arg, t_parsing *parsing)
{
	int i;

        i = 0;
	if (*arg)
	{ 
		while (arg[i] == '-' || arg[i] == '+' || arg[i] == '0' || arg[i] == ' ' || arg[i] == '#')
		{
		if (arg[i] == '-')
			parsing->flagstiret = -1;
		if (arg[i] == '0' && parsing->flagstiret != -1)
			parsing->flags0 = 1;
		if (parsing->flagstiret == 1)
			parsing->flags0 = 0;
		i++;
		}
	}
	return (i);
}


int	ft_width(char *arg, va_list *va, t_parsing *parsing)
{
	int i;
	
	i = 0;
	if (*arg && ft_isdigit(arg[i]))
	{
		if (parsing->flagstiret = -1)
			parsing->flagstiret = 1;
		parsing->width = ft_atoi(arg);
		while (ft_isdigit(arg[i]))
			i++;
	}
	else if (*arg && arg[i] == '*')	
	{
		if (parsing->flagstiret = -1)
			parsing->flagstiret = 1;
		parsing->width = va_arg(*va, unsigned int);
		i++;
	}
	return (i);

}

int	ft_precision(char *arg, va_list *va, t_parsing *parsing)
{
	int i;
	
	i = 0;
	if (*arg && arg[i] == '.')
	{
		i++;
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
	}
	return (i);
}

int	ft_lenght(char *arg, t_parsing *parsing)
{
	int i;
	
	i = 0;
	if (*arg && arg[i] == 'l')
	{
		parsing->lenght = 'l';
		if (arg[++i] == '1')
		{
			parsing->lenght = '2';
			i++;
		}

	}
	else if (*arg && arg[i] == 'h')
	{
		parsing->lenght = '3';
		if (arg[++i] == 'h')
		{
			parsing->lenght = '4';
			i++;
		}
	}
	else if (arg[i] == 'j' || arg[i] == 't' || arg[i] == 'z')
		i++;
	return(i);
}
