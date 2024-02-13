char	*ft_strcat(char *dest, char *src)
{
	int	i_dest;
	int i_src;

	i_dest = 0;
	i_src = 0;
	while (dest[i_dest] != '\0')
		++i_dest;
	while (src[i_src] != '\0')
	{
		dest[i_dest] = src[i_src];
		++i_dest;
		++i_src;
	}
	dest[i_dest] = '\0';
	return (dest);
}
