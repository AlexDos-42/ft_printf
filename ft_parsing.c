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
		parsing->flagstiret *= ft_atoi(arg);
		parsing->flags0 *= parsing->flagstiret;
		while (ft_isdigit(arg[i]))
			i++;
	}
	else if (*arg && arg[i] == '*')	
	{
		parsing->flagstiret *= va_arg(*va, unsigned int);
		parsing->flags0 *= parsing->flagstiret;
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
