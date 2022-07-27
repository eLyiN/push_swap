/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:47:11 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/27 13:49:55 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	chk_b_nd_push(t_program *s100, t_global *g, int *index)
{
	if (&g->stack_b.size <= 2)
	{
		swap_pb(&g->stack_b, &g->stack_a);
		if (&g->stack_b.array[0] > &g->stack_b.array[1]
			&& &g->stack_b.size == 2)
			swap_sb(&g->stack_b);
		return (0);
	}
	if (!check_sorted_nb(&g->stack_b))
	{
		place_bottom(&g->stack_b);
		swap_pb(&g->stack_b, &g->stack_a);
	}
	else
		swap_pb(&g->stack_b, &g->stack_a);
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
	mid = (stack->size / 2);
	i = 0;
	while (i <= mid && stack->array[i] != nb_max)
		i++;
	s100->hold_first = i;
	i = stack->size - 1;
	while (i >= mid && stack->array[i] != nb_max)
		i--;
	s100->hold_second = (stack->size) - i;
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

void	new_logic(t_program *s100, t_global *g, int *index)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	mid;

	mid = g->stack_b.size / 2;
	i = 0;
	while (g->stack_a.array[0] > g->stack_b.array[i] && i <= mid)
		i++;
	j = g->stack_b.size - 1;
	while (g->stack_a.array[0] < g->stack_b.array[j] && j >= mid)
		j--;
	if (i < j || i == j)
	{
		k = 0;
		while (i > 0)
		{
			swap_rb(&g->stack_b);
			i--;
			k++;
		}
		swap_pb(&g->stack_b, &g->stack_a);
		while (k > 0)
		{
			swap_rrb(&g->stack_b);
			k--;
		}
	}
	else
	{
		k = 0;
		while (j < g->stack_b.size - 1)
		{
			swap_rrb(&g->stack_b);
			j++;
			k++;
		}
		swap_pb(&g->stack_b, &g->stack_a);
		while (k > 0)
		{
			swap_rb(&g->stack_b);
			k--;
		}
	}
}

//usar get holds modificando el .cnk_max_count y luego devolviendo su valor
//ahorramos escribir codigo y puede servir para saber las posis del stack B
//a mover