#include "push_swap.h"

int	ft_isdigit(int i)
{
	if ((i >= 48) && (i <= 57))
		return (1);
	else
		return (0);
}

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

void	error(t_list **list_a)
{
	
	printf("Error");
	ft_putstr_fd("AAb", 1);
	if (!list_a)
		exit(1);
	if (list_a)
		ft_clear(list_a);
	exit(1);
}

int	parsing_add_one(char *str, t_list **list_a)
{
	static int	nb = 0;
	static int	flag = 0;
	int			cpnb;

	if (ft_isdigit(c))
	{	
		nb = ft_atoi(str);
	}
	else if (*str == 32 && flag)
	{
		cpnb = nb;
		nb = 0;
		flag = 0;
		return (cpnb);
	}
	else
		error(list_a);
	return(nb);
}

int main(int ac, char **av)
{
	int nb;
	int first_time;
	t_list *list_a;

	nb = 0;
	first_time = 1; 
	if (ac == 2)
	{
		while (*av[1])
		{
			nb = parsing_add_one(*av[1], &list_a);
			//printf("nb = %d /n", nb);
			if (*av[1] == 32)
			{
				if (first_time)
				{
					//printf("first %d", nb);
					list_a = ft_lstnew_int(nb);
					first_time = 0;
				}
				else
					ft_lstadd_front_int(&list_a, nb);
				//printf("nb = %d \n", nb);
			}
			av[1]++;
		}
		ft_lstadd_front_int(&list_a, nb);
	}
	//print(&list_a);
	printf("finis");
	
	ft_clear(&list_a);
	exit(1);
		// push dans la liste creer back int
}

