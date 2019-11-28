#include "ft_printf.h"

void		ft_s_precisionapp(char arg, t_parsing *parsing)
{
	char	*tmp;
	int		i;

	if (arg == 's' && parsing->precision >= 0)
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
		while (inf->p-- > ((int)ft_strlen(parsing->aff)) - (parsing->aff[0] == '-'))
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
	int		abs;

	i = 0;
	abs = ((parsing->flagstiret > 0) ? parsing->flagstiret : -parsing->flagstiret);
	if (parsing->flags0 > abs)
		abs = parsing->flags0;
	tmp = malloc(sizeof(char) * (abs + 1));
	if (!tmp)
		return ;
	while (abs-- > (int)ft_strlen(parsing->aff))
		tmp[i++] = ' ';
	tmp[i] = '\0';
	if (parsing->flagstiret > 0)
		tmp = ft_strjoin(tmp, parsing->aff);
	else
		tmp = ft_strjoin(parsing->aff, tmp);
	free(parsing->aff);
	parsing->aff = tmp;
}
