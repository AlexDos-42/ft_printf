#include "ft_printf.h"

void		ft_s_precisionapp(char arg, t_parsing *parsing)
{
	char	*tmp;

	if (arg == 's' && parsing->precision > 0)
	{
		tmp = ft_substr(parsing->aff, 0, parsing->precision);
		free(parsing->aff);
		parsing->aff = tmp;
	}
}
void		ft_precisionappnbr(t_parsing *parsing)
{
	char	*tmp;
	int		i;

	i = 0;
	if (parsing->precision > ((int)ft_strlen(parsing->aff) - (parsing->aff[0] == '-')))
	{
		if (!(tmp = malloc(sizeof(char*) * (parsing->precision + (parsing->aff[0] == '-') + 1))))
			return ;
		if (parsing->aff[0] == '-')
			tmp[i++] = '-';
		while (parsing->precision-- > ((int)ft_strlen(parsing->aff)) - (parsing->aff[0] == '-'))
			tmp[i++] = '0';
		tmp[i] = '\0';
		tmp = ft_strjoin(tmp, &(parsing->aff[(parsing->aff[0] == '-')]));
		free(parsing->aff);
		parsing->aff = tmp;
	}
}
void		ft_flagsapp(t_parsing *parsing)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = ((parsing->flagstiret > 0) ? parsing->flagstiret : -parsing->flagstiret);
	if (parsing->flags0 > j)
		j = parsing->flags0;
	if (!(tmp = malloc(sizeof(char) * (j + 1))))
		return ;
	while (j-- > ((parsing->aff != NULL ? ft_strlen(parsing->aff) : 0)))
		tmp[i++] = ' ';
	tmp[i] = '\0';
	if (parsing->flagstiret > 0)
		tmp = ft_strjoin(tmp, parsing->aff);
	else
		tmp = ft_strjoin(parsing->aff, tmp);
	free(parsing->aff);
	parsing->aff = tmp;
}

void		ft_exception(t_parsing *parsing, char arg)
{
	char	*tmp;

	if (arg =='d' || arg =='i' || arg =='u' || arg =='x' || arg =='X' || arg =='%')
	{
		if (parsing->precision == 0 && parsing->aff[0] == '0')
		{
			tmp = ft_strdup("");
			free(parsing->aff);
			parsing->aff = tmp;
		}
//		if (parsing->precision == -1)
//			parsing->precision = (parsing->aff[0] == '-') ? parsing->flags0 - 1 : parsing->flags0;
//		else if (parsing->precision < parsing->flags0 + (parsing->aff[0] == '-'))
//			parsing->flagstiret = parsing->flags0;
	}
	if (parsing->aff == NULL && arg == 's')
		parsing->aff = ft_strdup("(null)");
}

void		ft_app(char arg, t_parsing *parsing)
{
	char	*tmp;

	ft_exception(parsing, arg);
	ft_s_precisionapp(arg, parsing);
	if (parsing->precision >= 0 && (arg =='d' || arg =='i' || arg =='u' || arg =='x' || arg =='X' || arg =='%'))
		ft_precisionappnbr(parsing);
	if (arg == 'p')
	{
		tmp = ft_strjoin("0x", parsing->aff);
		free(parsing->aff);
		parsing->aff = tmp;
	}
	ft_flagsapp(parsing);
}
