void		ft_precisionapp(char **arg, t_parsing *parsing)
{
	char	*tmp;
	int		i;

	if (*arg == 's' && parsing->precision >= 0)
	{
		tmp = ft_substr(parsing->aff, 0, parsing->precision);
		free(parsing->aff);
		parsing->aff = tmp;
	}
}
