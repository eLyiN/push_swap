/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:47:11 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/26 19:46:24 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	chk_b_nd_push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size <= 1)
	{
		swap_pb(stack_b, stack_a);
		if (stack_b->array[0] > stack_b->array[1] && stack_b->size == 2)
			swap_sb(stack_b);
		return (0);
	}
	if (!check_sorted_nb(stack_b))
	{
		place_bottom(stack_b);
		swap_pb(stack_b, stack_a);
	}
	else
		swap_pb(stack_b, stack_a);
	return (0);
}

void	place_bottom(t_stack *stack)
{
	size_t	i;
	int		bottom;

	i = 0;
	bottom = find_smallest_nb(stack);
	while (stack->array[i] != bottom)
		i++;
	while (i != 0)
	{
		if (i == stack->size - 1)
		{
			swap_rrb(stack);
			return ;
		}
		swap_rb(stack);
		i--;
	}
}

void	place_top(t_program *s100, t_stack *stack)
{
	size_t	i;
	size_t	mid;
	int		nb_max;

	nb_max = find_highest_nb(stack);
	mid = stack->size / 2;
	i = 0;
	while (i < mid && stack->array[i] != nb_max)
		i++;
	if (stack->array[i] == nb_max)
		s100->hold_first = i;
	else
		s100->hold_first = -1;
	i = stack->size;
	while (i > mid && stack->array[i] != nb_max)
		i--;
	if (stack->array[i] == nb_max)
		s100->hold_second = i - stack->size + 1;
	else
		s100->hold_second = -1;
}

int	find_smallest_nb(t_stack *stack)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = stack->size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (stack->array[i] <= stack->array[j] && j < size)
			j++;
		if (j == size)
			return (stack->array[i]);
		i++;
	}
	return (0);
}

int	find_highest_nb(t_stack *stack)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = stack->size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (stack->array[i] >= stack->array[j] && j < size)
			j++;
		if (j == size)
			return (stack->array[i]);
		i++;
	}
	return (0);
}
