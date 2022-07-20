/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:32:10 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/20 13:52:23 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_arg(int ac, char *av[], t_stack stack_a)
{
	int		i;
	int		j;
	char	**temp;

	temp = ft_split(av, ' ');
	if (ft_isinteger(temp))
	{
		free(temp);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	i = -1;
	while (temp[i++])
	{
		stack_a.array[j] = ft_atoi(temp[i]);
	}
	return (0);
}

size_t	stack_counter(int ac, char *av[])
{
	size_t	size;
	int		i;
	int		j;

	i = -1;
	while (i++ < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((!j || av[i][j - 1] == ' ') && av[i][j] != ' ')
				size++;
			j++;
		}
	}
	return (size);
}

void	stacks_fill(int ac, char *av[], t_stack stack_a, t_stack stack_b)
{
	stack_a.max_size = stack_counter(ac, av);
	stack_b.max_size = stack_counter(ac, av);
	stack_a.size = 0;
	stack_b.size = 0;
	stack_a.array = malloc(sizeof(int) * stack_a.max_size);
	if (!stack_a.array)
		return (write(STDERR_FILENO, "Error\n", 6));
	stack_b.array = malloc(sizeof(int) * stack_b.max_size);
	if (!stack_b.array)
	{
		free(stack_a.array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	if (process_arg(ac, av, stack_a))
	{
		to_do = 0;
	}
}

int	main(int ac, char **av)
{
	t_global	global;

	if (ac < 2 || ac == 1)
		return (0);
	stacks_fill(ac, av, *global.a, *global.b);
}
