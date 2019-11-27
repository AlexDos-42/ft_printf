#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct		s_parsing
{
	int		flags;
	int		precision;
	int		width;
	char		*aff;
	int		lenght;
	int		flags0;
}			t_parsing;

void   ft_flags(char **arg, t_parsing *parsing);
void   ft_width(char **arg, t_parsing *parsing);
void	ft_precision(char **arg, t_parsing *parsing);
void	ft_lenght(char **arg, t_parsing *parsing);

#endif
