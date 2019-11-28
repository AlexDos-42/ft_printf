#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>


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

void		ft_flagsapp(t_parsing *parsing);
void		ft_s_precisionapp(char arg, t_parsing *parsing);
void		ft_precisionappnbr(t_parsing *parsing);
	
char	*ft_itoa_base(int nbr, int base);
char	*ft_strjoin_c(char const *s1, char c);
char	*ft_cdup(char c);

#endif
