/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:09:18 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/25 19:24:59 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_last_pos_b(t_stack *stack_b)
{
	int	i;
	int	j;
	int	size;

	size = stack_b->size - 1;
	i = 1;
	j = size - 1;
	while (stack_b->array[0] > stack_b->array[i] && i < size)
		i++;
	while (stack_b->array[size] > stack_b->array[j] && j != 0)
		j--;
	if (j == 0 && stack_b->array[size] > stack_b->array[j])
	{
		swap_rrb(stack_b);
		return (1);
	}
	if (i == size && stack_b->array[0] > stack_b->array[i])
		return (1);
	return (0);
}

int	find_first_pos_b(t_stack *stack_b)
{
	int	i;
	int	j;
	int	size;

	size = stack_b->size - 1;
	i = 1;
	j = size - 1;
	while (stack_b->array[0] < stack_b->array[i] && i < size)
		i++;
	while (stack_b->array[size] < stack_b->array[j] && j != 0)
		j--;
	if (j == 0 && stack_b->array[size] < stack_b->array[j])
	{
		swap_rrb(stack_b);
		return (1);
	}
	if (i == size && stack_b->array[0] < stack_b->array[i])
		return (1);
	return (0);
}

void	perform_rest_sort_b(t_stack *stack_b, t_stack *stack_a)
{
	size_t	i;
	size_t	size;

	swap_pb(stack_b, stack_a);
	size = stack_b->size;
	i = 1;
	while (stack_a->array[0] > stack_a->array[i] && i != size)
		i++;
	if (i == size)
		swap_ra(stack_a);
}
