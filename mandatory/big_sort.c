/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:11:02 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/26 19:48:38 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	chunk_phase(t_program *s100, t_global *g, int *index)
{
	get_holds(s100, &g->stack_a, index);
	if (s100->hold_first < s100->hold_second && s100->hold_first != -1
		&& s100->hold_second != -1)
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
	chk_b_nd_push(&g->stack_a, &g->stack_b);
	s100->chnk_count++;
	return (0);
}

int	push_b_phase(t_program *s100, t_global *g)
{
	if (s100->hold_first < s100->hold_second && s100->hold_first != -1
		&& s100->hold_second != -1)
	{
		while (s100->hold_first >= 0)
		{
			swap_rb(&g->stack_b);
			s100->hold_first--;
		}
	}
	else
	{
		while (s100->hold_second >= 0)
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

	start_program(&s100, global);
	index = malloc(sizeof(int) * global->stack_a.size);
	if (!index)
		return (write(STDERR_FILENO, "Error\n", 6));
	if (simple_indexation(&s100, &global->stack_a, index))
		return (1);
	while (s100.chnk_count < s100.chnk_max_stack)
	{
		chunk_phase(&s100, global, index);
	}
	while (global->stack_b.size > 0)
	{
		place_top(&s100, &global->stack_b);
		push_b_phase(&s100, global);
	}
	return (0);
}

int	start_program(t_program *s100, t_global *global)
{
	s100->chnk_count = 0;
	s100->chnk_stack = 0;
	if (global->stack_a.size >= 19)
		s100->chnk_max_stack = 19;
	else
		s100->chnk_max_stack = global->stack_a.size;
	s100->high_nb = 0;
	s100->low_nb = 0;
	s100->hold_first = -1;
	s100->hold_second = -1;
	s100->nb_swaped = 0;
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
		while (i < stack_a->size)
		{
			if (index[i] == lw_nb)
			{
				index[i] = i;
				break ;
			}
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
		if (index[i] < (int)s100->chnk_max_stack)
			s100->hold_first = i;
		i++;
	}
	i = stack->size;
	while (i > mid && s100->hold_second != (int)i - (int)mid)
	{
		if (index[i] < (int)s100->chnk_max_stack)
			s100->hold_second = i - mid;
		i--;
	}
}
