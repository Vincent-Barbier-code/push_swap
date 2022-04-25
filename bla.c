#include <stdio.h>
int	ft_atoi(const char *str)
{
	int			i;
	int			signe;
	long int	nb;

	signe = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = signe * nb;
	return (nb);
}

int main()
{
    printf("%d", ft_atoi("    -343 43"));
}