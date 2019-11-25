#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void   ft_flags(char **arg, t_parsing *parsing)
{
	if (*arg)
	{ 
		if (arg == '-' || arg == '+' || arg == '0' || arg == " " || arg == "#")
			parsing->flags = arg++;
		else
			parsing->flags = '\0';	
	}
}


void	ft_width(char **arg, t_parsing *parsing)
{

	if (*arg && ft_isdigit(*arg))
	{
		parsing->width = ft_atoi(*arg);
		//incrémenter arg en f° atoi
	}
	else if (*arg && *arg == "*")	
	{
		*arg++;
	}	
	else
		parsing->width = '\0';	

}

void	ft_precision(char **arg, t_parsing *parsing)
{
	if (*arg && *arg == '.')
	{
		arg++;
		if (*arg && ft_isdigit(*arg))
		{
			parsing->precision = ft_atoi(*arg);
			//incrémenter arg en f° atoi
			else if (*arg && *arg == "*")	
			{
				*arg;
			}
			else	
				parsing->precision = '\0';	
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
		else
			parsing->lenght = '\0';
	}
}

void ft_type(char **arg, t_parsing *parsing)
{
	if (*arg && *arg == c)
		ft_typec
	else if (*arg && *arg == s)
		ft_types
	else if (*arg && *arg == p)
		ft_typep
	else if (*arg && *arg == d)
		ft_typed
	else if (*arg && *arg == i)
		ft_typei
	else if (*arg && *arg == u)
		ft_typeu
	else if (*arg && (*arg == x || *arg == X))
		ft_typexX
	else if (*arg && *arg == f)
		ft_typef
	else if (*arg && *arg == g)
		ft_typeg
	else if (*arg && *arg == e)
		ft_typee
	else if (*arg && *arg == n)
		ft_typen
}

void		ft_init_parsing(t_parsing *parsing)
{
	parsing->format = NULL;
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
	parsing->aff = ft_type(&arg, &parsing);
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
	if (!(parsing = (t_parsing*)malloc(sizeof(t_parsingi))))
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
