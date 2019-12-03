#include <stdio.h>
#include "ft_printf.h"

void ft_type(char type, va_list *va, t_parsing *parsing)
{
	if (type == 'c')
		parsing->aff = ft_cdup(va_arg(*va, int));
	else if (type == '%')
		parsing->aff = ft_cdup('%');
	else if (type == 's')
		parsing->aff = ft_strdup(va_arg(*va, char*));
	else if (type == 'd' || type == 'i')
		parsing->aff = ft_itoa(va_arg(*va, int));
	else if (type == 'u')
		parsing->aff = ft_itoa_base(va_arg(*va, unsigned long), "0123456789"); 
	else if (type == 'x')
		parsing->aff = ft_itoa_base(va_arg(*va, unsigned long), "0123456789abcdef");
	else if (type == 'X')
		parsing->aff = ft_itoa_base(va_arg(*va, unsigned long), "0123456789ABCDEF");
	else if (type == 'p')
		parsing->aff = ft_itoa_base(va_arg(*va, unsigned long long int), "0123456789abcdef");
}

void		ft_init_parsing(t_parsing *parsing)
{
	parsing->flagstiret = 0;
	parsing->flags0 = 0;
	parsing->precision = -1;
	parsing->aff = NULL;
}

int		ft_parsing(char *arg, va_list *va, t_parsing *parsing)
{
	int i;
	
	i = 0;
	i +=ft_flags(&arg[i], parsing);
	i +=ft_width(&arg[i], va, parsing);
	i +=ft_precision(&arg[i], va, parsing);
	ft_type(arg[i], va, parsing);
	ft_app(arg[i], parsing);
	if (arg[i] == 'c' || arg[i] == 'd' || arg[i] == 'i' || arg[i] == '%' || arg[i] == 'x' ||
			arg[i] == 'X' || arg[i] == 'u' || arg[i] == 'p' ||  arg[i] == 's')
		return (++i);
	return (-1);
}

char 	*ft_boucle(char *arg, va_list *va, t_parsing *parsing)
{
	char *tmp;
	char *put;

	put = ft_calloc(1, 1);
	while (*arg)
	{
		ft_init_parsing(parsing);
		if (*arg == '%')
		{
			arg++;
			arg += ft_parsing(arg, va, parsing);
			if (parsing->aff)
				tmp = ft_strjoin(put, parsing->aff);
		}
		if (!parsing->aff) 
		{
			tmp = ft_strjoin_c(put, *arg);
			arg++;
		}
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
	put = ft_boucle(arg, &va, parsing);
	ft_putstr_fd(put, 1);
	len = ft_strlen(put);
	va_end(va);
	free(put);
	return (len);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	ft_printf("debut %x fin\n____\n", 1100);
	ft_printf("%x\n____\n", 1100);
	printf("debut %x fin\n____\n", 1100);
	return (0);*/
