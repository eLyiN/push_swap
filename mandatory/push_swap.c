/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:32:10 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/21 14:00:58 by aarribas         ###   ########.fr       */
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
	return (0);
}
