/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:32:10 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/20 11:54:44 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacks_fill(int ac, char *av[], t_stack stack_a, t_stack stack_b)
{
	stack_a.array = ft_split(av, ' ');
}

int	main(int ac, char **av)
{
	t_global	global;

	if (ac < 2 || ac == 1)
		return (0);
	stacks_fill(ac, av, *global.a, *global.b);
}
