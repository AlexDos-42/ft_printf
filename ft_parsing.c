#include "ft_printf.h"

void   ft_flags(char **arg, t_parsing *parsing)
{
	if (*arg)
	{ 
		while (arg == '-' || arg == '+' || arg == '0' || arg == " " || arg == "#")
		{
		if (arg == '-')
			parsing->flags- = -1;
		if (arg == '0' && parsing->flags- != -1)
			parsing->flags0 = 1;
		if (parsing->flags- == 1)
			parsing->flags0 = 0;
		}
	}
}


void	ft_width(char **arg, t_parsing *parsing)
{

	if (*arg && ft_isdigit(*arg))
	{
		if (parsing->flags- = -1;)
			parsing->flags- = 1;
		parsing->width = ft_atoi(*arg);
		while (ft_isdigit(*arg))
			*arg++;
	}
	else if (*arg && *arg == "*")	
	{
		if (parsing->flags- = -1;)
			parsing->flags- = 1;
		parsing->width = va_arg(*va, unsigned int)
		*arg++;
	}	

}

void	ft_precision(char **arg, t_parsing *parsing)
{
	if (*arg && *arg == '.')
	{
		arg++;
		if (*arg && ft_isdigit(*arg))
		{
			parsing->precision = ft_atoi(*arg);
			while (ft_isdigit(*arg))
				*arg++;
		}
		else if (*arg && *arg == "*")	
		{
			parsing->precision = va_arg(*va, unsigned int)
			*arg++;
		}
	}
}

void	ft_lenght(char **arg, t_parsing *parsing)
{
	if (*arg && *arg == 'l')
	{
		parsing->lenght = 'l';
		if (*++arg == 'l')
		{
			parsing->lenght = 'll';
			arg++;
		}

	}
	else if (*arg && *arg == 'h')
	{
		parsing->lenght = 'h';
		if (*++arg == 'h')
		{
			parsing->lenght = 'hh';
			arg++;
		}
	else if (*arg == 'j' || *arg == 't' || *arg == 'z')
		parsing->lenght = *arg++;
	
}
