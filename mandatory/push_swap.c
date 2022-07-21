/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:32:10 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/22 01:13:59 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_global	global;

	if (ac < 2)
		return (1);
	if (stacks_fill(--ac, &av[1], &global.stack_a, &global.stack_b))
		return (1);
	printf("%d\n", global.stack_a.array[1]);
	printf("%s\n", av[2]);
	printf("Max_SIZE:%ld\n", global.stack_a.max_size);
	printf("Size: %ld\n", global.stack_a.size);
	printf("Test PA: stack_a before pa: %d\n", global.stack_a.array[0]);
	swap_ra(&global.stack_a);
	printf("Test RA: stack_a after pa: %d it should be 2\n",
			global.stack_a.array[0]);
	printf("Test PA: stack_a[1] after pa: %d it should be 3\n",
			global.stack_a.array[1]);
	printf("Test PA: stack_a[2] after pa: %d it should be 1\n",
			global.stack_a.array[2]);
	printf("Test PA: size stack_a after pa: %ld\n", global.stack_a.size);
	return (0);
}
