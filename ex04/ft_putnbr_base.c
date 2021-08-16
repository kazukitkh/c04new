//#include <stdio.h>
#include <unistd.h>

void	ft2_write(char *base, int nbr, int j, int *n)
{
	while (n[1])
	{
		n[2] = n[1] - 1;
		n[3] = nbr;
		while (n[2])
		{
			n[3] /= j;
			n[2]--;
		}
		n[4] = n[3] % j;
		if (n[0] && n[1] == 1 && base[n[4] + 1])
			n[4] += 1;
		if (n[0] && n[1] == 1 && !base[n[4] + 1])
			n[4] = 0;
		write(1, &base[n[4]], 1);
		n[1]--;
	}
}

void	ft1_write(char *base, int nbr, int j)
{
	char	t[2];
	int		n[5];

	t[0] = '-';
	if (nbr < 0)
	{
		write(1, t, 1);
		if (nbr == -2147483648)
		{
			n[0] = 8;
			nbr = -2147483647;
		}
		nbr = -nbr;
	}
	n[1] = 0;
	n[2] = nbr;
	if (!n[2])
		n[1] = 1;
	while (n[2])
	{
		n[2] /= j;
		n[1]++;
	}
	ft2_write(base, nbr, j, n);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		j;
	int		a;

	i = 0;
	j = 0;
	a = 1;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			a = 0;
		while (base[j])
		{
			if (base[i] == base[j])
				a = 0;
			j++;
		}
		i++;
	}
	if (j < 2)
		a = 0;
	if (a)
		ft1_write(base, nbr, j);
}

/*int	main(void)
{
	int		n = 9000;
	char	s[] = "";
	ft_putnbr_base(n, s);
	putchar('\n');
	return (0);
}*/