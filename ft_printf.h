#ifndef FT_PRINTF_H
#define FT_PRINTF_H

typedef struct		s_parsing
{
	int		flags;
	int		precision;
	int		width;
	int		type;
	int		signe;
}			t_parsing;

void   ft_flags(char **arg, t_parsing *parsing);
void   ft_width(char **arg, t_parsing *parsing);
void	ft_precision(char **arg, t_parsing *parsing);

#endef
