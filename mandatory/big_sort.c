/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:11:02 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/27 13:18:41 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	chunk_phase(t_program *s100, t_global *g, int *index)
{
	if (g->stack_a.size > 2)
	{
		get_holds(s100, &g->stack_a, index);
		if (s100->hold_first < s100->hold_second
			|| s100->hold_first == s100->hold_second)
		{
			while (s100->hold_first != 0)
			{
				swap_ra(&g->stack_a);
				s100->hold_first--;
			}
		}
		else
		{
			while (s100->hold_second != 0)
			{
				swap_rra(&g->stack_a);
				s100->hold_second--;
			}
		}
	}
	chk_b_nd_push(&g->stack_a, &g->stack_b);
	s100->chnk_count++;
	return (0);
}

int	push_b_phase(t_program *s100, t_global *g)
{
	if (s100->hold_first < s100->hold_second
		|| s100->hold_first == s100->hold_second)
	{
		while (s100->hold_first != 0)
		{
			swap_rb(&g->stack_b);
			s100->hold_first--;
		}
	}
	else
	{
		while (s100->hold_second != 0)
		{
			swap_rrb(&g->stack_b);
			s100->hold_second--;
		}
	}
	swap_pa(&g->stack_a, &g->stack_b);
	return (0);
}

int	start_sort_big(t_global *global)
{
	t_program	s100;
	int			*index;
	int			i;

	start_program(&s100, global);
	index = malloc(sizeof(int) * global->stack_a.size);
	if (!index)
		return (write(STDERR_FILENO, "Error\n", 6));
	if (simple_indexation(&s100, &global->stack_a, index))
		return (1);
	while (s100.chnk_count < global->stack_a.max_size)
	{
		chunk_phase(&s100, global, index);
		if (s100.chnk_count == s100.chnk_max_count)
			get_next_chunk(&s100);
	}
	i = -1;
	while (++i < (int)global->stack_b.size)
		printf("STACK_B[%d]: %d\n", i, global->stack_b.array[i]);
	free(index);
	while (global->stack_b.size != 0)
	{
		place_top(&s100, &global->stack_b);
		push_b_phase(&s100, global);
	}
	i = -1;
	while (++i < (int)global->stack_a.size)
		printf("STACK_A[%d]: %d\n", i, global->stack_a.array[i]);
	return (0);
}

void	get_next_chunk(t_program *s100)
{
	s100->chnk_stack++;
	s100->chnk_max_count *= s100->chnk_stack;
}

int	start_program(t_program *s100, t_global *global)
{
	s100->chnk_count = 0;
	s100->chnk_stack = 1;
	if (global->stack_a.max_size <= 100)
	{
		s100->chnk_max_stack = 5;
		s100->chnk_max_count = global->stack_a.max_size / s100->chnk_max_stack;
	}
	else
	{
		s100->chnk_max_stack = 11;
		s100->chnk_max_count = global->stack_a.max_size / s100->chnk_max_stack;
	}
	s100->high_nb = 0;
	s100->low_nb = 0;
	s100->hold_first = 0;
	s100->hold_second = 0;
	s100->low_nb = find_smallest_nb(&global->stack_a);
	s100->high_nb = find_highest_nb(&global->stack_a);
	return (0);
}

int	simple_indexation(t_program *s100, t_stack *stack_a, int *index)
{
	size_t	i;
	int		lw_nb;

	lw_nb = s100->low_nb;
	while (lw_nb != s100->high_nb + 1)
	{
		i = 0;
		while (i < stack_a->size && index[i - 1] != i - 1)
		{
			if (index[i] == lw_nb)
				index[i] = i;
			i++;
		}
		lw_nb++;
	}
	return (0);
}

void	get_holds(t_program *s100, t_stack *stack, int *index)
{
	size_t	i;
	size_t	mid;

	mid = stack->size / 2;
	i = 0;
	while (i < mid && s100->hold_first != (int)i)
	{
		if (index[i] < (int)s100->chnk_max_count)
			s100->hold_first = i + 1;
		i++;
	}
	i = stack->size;
	while (i > mid && s100->hold_second != (int)i - (int)mid)
	{
		if (index[i] < (int)s100->chnk_max_count)
			s100->hold_second = (mid - i) + 1;
		i--;
	}
}
