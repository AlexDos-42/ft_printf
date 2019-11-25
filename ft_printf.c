#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

void   ft_flags(char **arg, t_parsing *parsing)
{
	if (*arg)
	{ 
		while (arg == '-' || arg == '+' || arg == '0' || arg == " " || arg == "#")
		{
		if (arg == '-')
			parsing->flags- = 1;
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
		parsing->width = ft_atoi(*arg);
		while (ft_isdigit(*arg))
			*arg++;
	}
	else if (*arg && *arg == "*")	
	{
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

void ft_type(char **arg, va_list va, t_parsing *parsing)
{
	if (*arg == 'c')
		parsing->aff = ft_strdup_c(va_arg(*va, int));
	else if (*arg == 's')
		parsing->aff = ft_strdup(va_arg(*va, char*));
	else if (*arg == 'd' || *arg == 'i')
		parsing->aff = ft_itoa(va_arg(*va, int));
	else if (*arg == 'u')
	else if (*arg == 'x')
	else if (*arg == 'X')
	else if (*arg == '%')
	else if (*arg == 'p')
}

void		ft_init_parsing(t_parsing *parsing)
{
	parsing->flags- = NULL;
	parsing->flags0 = NULL;
	parsing->width = NULL;
	parsing->precision = NULL;
	parsing->lenght = NULL;
	parsing->type = NULL;
	parsing->aff = NULL;
}

void		ft_parsing(char *arg, va_list va)
{
	int i;

	ft_format(&arg, &parsing);
	ft_width(&arg, &parsing);
	ft_precision(&arg, &parsing);
	ft_lenght(&arg, &parsing);
	ft_type(&arg, &parsing);
}

char 	*ft_format(char **arg, va_list va, t_parsing *parsing)
{
	char *tmp;

	while (*arg)
	{
		ft_init_parsing(parsing);
		if (*arg == '%')
		{
			arg++ += ft_parsing(&arg, va);
			if (parsing->aff)
				tmp = ft_strjoin(new_s, parsing->aff);
		}
		else 
		//	tmp = 
	free(parsing->aff);
	free(put);
	put = tmp;
	}
	return (put);
}

int	ft_printf(const char *format, ...)
{
	char *arg;
	va_list	va;	
	int len;
	char* put;
	t_parsing *parsing;

	if (format == NULL)
		return (-1);
	if (!(parsing = (t_parsing*)malloc(sizeof(t_parsing))))
		return (0);
	va_start(va, format);
	arg = (char *)format;
	put = ft_format(&arg, va, parsing);
	ft_putstr_fd(put, 1);
	len = ft_strlen(put);
	va_end(va);
	return (len);
}

int	main(int ac, char **av)
{
	(void)ac;
	ft_printf(av[1]);
	printf("bonjour\n");
	return (0);
}
