#include "push_swap.h"

int	ft_isdigit(int i)
{
	if ((i >= 48) && (i <= 57))
		return (1);
	else
		return (0);
}

t_put	ft_atoi(const char *str)
{
	int			i;
	int			signe;
	long int	nb;
	t_put		put;

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
	put.nb = signe * nb;
	put.pass = i;
	return (put);
}

void	error()
{	
	printf("Error");
	exit(1);
}

t_list	*fill_list_a(char *str)
{
	t_put	put;
	int		copy;
	t_list	*list;
	static int		start = 1;

	copy = 0;
	while (*str)
	{
		put = ft_atoi(str);
		if (copy != put.nb)
		{
			if (start)
			{
				list = ft_lstnew_int(put.nb);
				start = 0;
				printf("nb F= %d \n",put.nb);
			}
			else
			{
				ft_lstadd_front_int(&list, put.nb);		
				printf("nb = %d \n",put.nb);
			}
		}
		copy = put.nb;
		while(put.pass--)
			str++;
	}
	return(list);
}

int	parsing(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 3;
	while(str[i + 1])
	{
		if ((str[i] == '-' || str[i] == '+') && (flag != 1 && flag != 2) )
			flag = 1;
		else if (str[i] >= '0' && str[i] <= '9')
			flag = 2;
		else if (str[i] == ' ' && (flag != 1 && flag != 3))
			flag = 3;
		else
			error();
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		error();
	return(1);
}

int main(int ac, char **av)
{
	int i;
	t_list *list_a;

	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
			if (!parsing(av[i++]))
				error();
	}
	else
		exit(1);
	i = 1;
	while (i < ac)
	{
		list_a = fill_list_a(av[i++]);
	}
	printf("finis");	
	print(&list_a);
	printf("\n");
	ft_clear(&list_a);
	exit(1);
		// push dans la liste creer back int
}

