unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	const size_t	size_src = ft_strlen(src);
	size_t			size_dst;

	if (dst == NULL)
		size_dst = 0;
	else
		size_dst = ft_strlen(dst);
	if (size <= size_dst)
		return (size + size_src);
	ft_strlcpy(dst + size_dst, src, size - size_dst);
	return (size_dst + size_src);
}
