#include <stdio.h>
#include "ft_printf.h"

void ft_type(char **arg, va_list va, t_parsing *parsing)
{
	if (*arg == 'c')
		parsing->aff = ft_cdup(va_arg(*va, int));
	else if (*arg == 's')
		parsing->aff = ft_strdup(va_arg(*va, char*));
	else if (*arg == 'd' || *arg == 'i')
		parsing->aff = ft_itoa(va_arg(*va, int));
	else if (*arg == 'u')
		parsing->aff = ft_itoa_base(va_arg(*va, unsigned long), 10); 
	else if (*arg == 'x')
		parsing->aff = ft_itoa_base(va_arg(*ap, unsigned long), 16);
	else if (*arg == 'X')
		parsing->aff = ft_itoa_base(va_arg(*ap, unsigned long), 16);
	else if (*arg == '%')
		parsing->aff = ft_cdup('%');
	else if (*arg == 'p')
		parsing->aff = ft_itoa_base(va_arg(*ap, unsigned long), 16);
}

void		ft_init_parsing(t_parsing *parsing)
{
	parsing->flags- = 0;
	parsing->flags0 = 0;
	parsing->width = 0;
	parsing->precision = 0;
	parsing->lenght = 0;
	parsing->aff = NULL;
}

void		ft_parsing(char *arg, va_list va, parsing)
{
	ft_format(&arg, &parsing);
	ft_width(&arg, va, &parsing);
	ft_precision(&arg, va, &parsing);
	ft_lenght(&arg, &parsing);
	ft_type(&arg, va, &parsing);
}

char 	*ft_format(char **arg, va_list va, t_parsing *parsing)
{
	char *tmp;
	char *put;
	
	while (*arg)
	{
		ft_init_parsing(parsing);
		if (*arg == '%')
		{
			arg++ += ft_parsing(&arg, va, parsing);
			if (parsing->aff)
				tmp = ft_strjoin(put, parsing->aff);
		}
		else 
			tmp = ft_strjoin_c(put, parsing->aff);
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
