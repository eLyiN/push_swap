/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:32:10 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/26 10:47:50 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sorted_nb(t_stack *stack_a)
{
	size_t	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->array[i] < stack_a->array[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_global	global;
	size_t		i;

	if (ac < 2)
		return (1);
	if (stacks_fill(--ac, &av[1], &global.stack_a, &global.stack_b))
		return (1);
	if (check_sorted_nb(&global.stack_a))
		return (0);
	if (global.stack_a.size <= 5)
		if (start_sort_small(&global.stack_a, &global.stack_b))
			return (1);
	if (global.stack_a.size > 5)
		start_sort_big(&global);
	i = -1;
	while (++i < global.stack_a.size)
		printf("Stack_A[%ld]:%d \n", i, global.stack_a.array[i]);
	i = -1;
	while (++i < global.stack_b.size)
		printf("Stack_B[%ld]:%d \n", i, global.stack_b.array[i]);
	return (0);
}
