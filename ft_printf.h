/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:35:15 by alesanto          #+#    #+#             */
/*   Updated: 2019/12/14 16:46:54 by alesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_parsing
{
	int				flagstiret;
	int				precision;
	char			*aff;
	int				flags0;
	int				c;
	int				w;
	int				z;
}					t_parsing;

int					ft_printf(const char *format, ...);
int					ft_boucle(char *arg, va_list *va);
int					ft_parsing(char *arg, va_list *va, t_parsing *parsing);
void				ft_init_parsing(t_parsing *parsing);
void				ft_init_parsing(t_parsing *parsing);

int					ft_flags(char *arg, t_parsing *parsing);
int					ft_width(char *arg, va_list *va, t_parsing *parsing);
int					ft_precision(char *arg, va_list *va, t_parsing *parsing);
int					ft_lenght(char *arg, t_parsing *parsing);

void				ft_flagsapp(t_parsing *parsing, char arg);
void				ft_s_precisionapp(char arg, t_parsing *parsing);
void				ft_precisionappnbr(t_parsing *parsing);
void				ft_app(char arg, t_parsing *parsing);
void				ft_exception(t_parsing *parsing, char arg);

char				*ft_itoa_base(unsigned long long int nbr, char *base);
char				*ft_strjoin_c(char const *s1, char c);
char				*ft_cdup(int c);

#endif
