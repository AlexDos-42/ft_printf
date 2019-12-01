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
		parsing->aff = ft_itoa_base(va_arg(*va, unsigned long), "0123456789abcdef");
}

void		ft_init_parsing(t_parsing *parsing)
{
	parsing->flagstiret = 1;
	parsing->flags0 = 0;
	parsing->precision = -1;
	//parsing->lenght = 0;
	parsing->aff = NULL;
}

int		ft_parsing(char *arg, va_list *va, t_parsing *parsing)
{
	int i;
	
	i = 0;
	i +=ft_flags(&arg[i], parsing);
	i +=ft_width(&arg[i], va, parsing);
	i +=ft_precision(&arg[i], va, parsing);
	//i +=ft_lenght(&arg[i], parsing);
	ft_type(arg[i], va, parsing);
	ft_app(arg[i], parsing);
	if (arg[i] == 'c' || arg[i] == 'd' || arg[i] == 'i' || arg[i] == '%' || arg[i] == 'x' ||
		arg[i] == 'X' ||  arg[i] == 'p' ||  arg[i] == 's')
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
		else 
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
	#include "ft_printf.h"
#include <stdio.h>
int main()
{
	char *str = "hello !";
    char *vide = "";
    char *ptr_nul = NULL;
    char c = 'c';
    char char_nul = 0;
    char char_sp = ' ';
    int max = 2147483647;
    int min = -2147483648;
    int pos = 42;
    int neg = -209;
    int z = 0;
    unsigned int u_max = 4294967295;
    unsigned int u_min = 0;
    printf("***************\nFORMAT C\n***************\n-> ignorer +, precision, 0width\n\n");
    printf("COMPORTEMENTS DEFINIS\n");
    ft_printf("MY_PRINTF\t['c']\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", c, c, c, c, c);
    printf("VRAI_PRINTF\t['c']\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", c, c, c, c, c);
    ft_printf("MY_PRINTF\t[null]\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", char_nul, char_nul, char_nul, char_nul, char_nul);
    printf("VRAI_PRINTF\t[null]\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", char_nul, char_nul, char_nul, char_nul, char_nul);
    ft_printf("MY_PRINTF\t[space]\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", char_sp, char_sp, char_sp, char_sp, char_sp);
    printf("VRAI_PRINTF\t[space]\t|%c|\t|%3c|\t|%-3c|\t|%15c|\t|%-15c|\n", char_sp, char_sp, char_sp, char_sp, char_sp);
    printf("\n/!\\ UNDEFINED BEHAVIOR\n");
    ft_printf("MY_PRINTF\t['c']\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", c, c, c, c, c);
    printf("VRAI_PRINTF\t['c']\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", c, c, c, c, c);
    ft_printf("MY_PRINTF\t[null]\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", char_nul, char_nul, char_nul, char_nul, char_nul);
    printf("VRAI_PRINTF\t[null]\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", char_nul, char_nul, char_nul, char_nul, char_nul);
    ft_printf("MY_PRINTF\t[space]\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", char_sp, char_sp, char_sp, char_sp, char_sp);
    printf("VRAI_PRINTF\t[space]\t|%.3c|\t|%3.3c|\t|%-3.3c|\t|%15.3c|\t|%-15.3c|\n", char_sp, char_sp, char_sp, char_sp, char_sp);

    printf("\n***************\nFORMAT S\n***************\n-> ignorer +, 0width\n\n");
    ft_printf("MY_PRINTF\t[chaine]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", str, str, str, str, str, str, str, str, str, str);
    printf("VRAI_PRINTF\t[chaine]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", str, str, str, str, str, str, str, str, str, str);
    ft_printf("MY_PRINTF\t[chaine -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", str, str, str, str, str, str, str, str, str, str);
    printf("VRAI_PRINTF\t[chaine -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", str, str, str, str, str, str, str, str, str, str);

    ft_printf("MY_PRINTF\t[vide   ]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", vide, vide, vide, vide, vide, vide, vide, vide, vide, vide);
    printf("VRAI_PRINTF\t[vide   ]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", vide, vide, vide, vide, vide, vide, vide, vide, vide, vide);
    ft_printf("MY_PRINTF\t[vide -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", vide, vide, vide, vide, vide, vide, vide, vide, vide, vide);
    printf("VRAI_PRINTF\t[vide -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", vide, vide, vide, vide, vide, vide, vide, vide, vide, vide);

    ft_printf("MY_PRINTF\t[null   ]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul);
    printf("VRAI_PRINTF\t[null   ]\t|%s|\t|%12s|\t|%3s|\t|%.12s|\t|%.3s|\t|%12.3s|\t|%3.3s|\t|%3.12s|\t|%12.12s|\t|%.0s|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul);
    ft_printf("MY_PRINTF\t[null -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul);
    printf("VRAI_PRINTF\t[null -]\t|%-s|\t|%-12s|\t|%-3s|\t|%-.12s|\t|%-.3s|\t|%-12.3s|\t|%-3.3s|\t|%-3.12s|\t|%-12.12s|\t|%-.0s|\n", ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul, ptr_nul);
}
