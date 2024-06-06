
#include "./include/libft.h"

/* man strcpy | function copies the string pointed to by src,
including the terminating null byte ('\0'),
to the buffer pointed to by dest. */
char	*ft_strcpy(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}