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
	
	if (ft_isdigit(*arg))
		parsing->width = ft_atoi(*arg);
		//incrémenter arg en f° atoi
	else if (**arg == "*")		
	else
		parsing->width = '\0';	

}

void	ft_precision(char **arg, t_parsing *parsing)
{
	if (*arg == '.')
	{
		arg++;


	}
}


void	ft_lenght(char **arg, t_parsing *parsing)
{
	
}

int		ft_parsing(char *arg, va_list va)
{
	int i;
	t_parsing parsing;

	ft_format(&arg, &parsin);
	ft_width(&arg, &parsing);
	ft_precision(&arg, &parsing);
	ft_lenght(&arg, &parsing);

	return(i);
}
int		ft_printf(const char *format, ...)
{
	char *arg;
	va_list	va;	
	int len;
	
	va_start(va, format);
	arg = (char *)format;
	printf("test\n");
	while (*arg)
	{
		if (*arg == '%')
			arg++;
			ft_parsing(arg, va);
		else 
			write(1, arg, 1);
		++arg;
	}
	printf("testf\n");
	va_end(va);
	len = 1;
	return (len);
}

int	main(int ac, char **av)
{
	(void)ac;
	ft_printf(av[1]);
	printf("bonjour\n");
	return (0);
}
