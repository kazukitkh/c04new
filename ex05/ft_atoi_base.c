#include <stdio.h>

int	ft_itoi2(char *str, char *base, int j, int t)
{
	int	nb;
	int	i;
	int	k;
	int	s;

	i = 0;
	k = 0;
	while (str[i])
	{
		s = i;
		nb = str[i] - '0';
		while (s < t)
		{
			nb *= j;
			s ++;
		}
		k += nb;
		i ++;
	}
	return (k);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	int		k;
	int		a;

	i = 0;
	a = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == str[i])
			{
				a++;
				str[i] = j + '0';
			}
			if (base[j] == 43 || base[j] == 45)
				return (0);
			j ++;
		}
		if (a != 1 || !j || j == 1)
			return (0);
		i ++;
	}
	if (!(a == i))
		return (0);
	a = ft_itoi2(str, base, j, i - 1);
	return (a);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	printf("%d\n", ft_atoi_base(argv[1], argv[2]));
	return (0);
}