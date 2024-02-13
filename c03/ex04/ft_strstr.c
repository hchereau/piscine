char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	y;

	i =0;
	while (str[i] != '\0')
	{
		j = 0;
		while(to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			++j;
		}
		++i;
	}
	return(0);
}
