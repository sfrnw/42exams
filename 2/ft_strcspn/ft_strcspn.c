#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i;
	int k;

	i = 0;
	k = 0;
	
	while (s[i] != '\0')
	{
		while(reject[k] != '\0')
		{
			if (reject[k] == s[i])
				return (i);
			k++;
		}
		k = 0;
		i++;
	}
	return (i);
}
// int	main()
// {
// 	printf("%lu\n", ft_strcspn("test", "es"));
// 	printf("%lu\n", strcspn("test", "es"));
// 	printf("%lu\n", ft_strcspn("test", "f"));
// 	printf("%lu\n", strcspn("test", "f"));
// 	return (0);
// }
