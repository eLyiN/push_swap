/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:11:02 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/28 10:45:08 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	chunk_phase(t_program *s100, t_global *g, int *index)
{
	if (g->stack_a.size > 2)
	{
		printf("hold_first:%d\n", s100->hold_first);
		printf("hold_second:%d\n", s100->hold_second);
		if (s100->hold_first < s100->hold_second
			|| s100->hold_first == s100->hold_second)
		{
			while (s100->hold_first != 0)
			{
				swap_ra(&g->stack_a);
				index_ra(index, &g->stack_a);
				s100->hold_first--;
			}
		}
		else
		{
			while (s100->hold_second != 0)
			{
				swap_rra(&g->stack_a);
				index_ra(index, &g->stack_a);
				s100->hold_second--;
			}
		}
	}
	chk_b_nd_push(g, index);
	s100->chnk_count++;
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
	simple_indexation(&s100, &global->stack_a, index);
	i = -1;
	while (s100.chnk_count < global->stack_a.max_size)
	{
		get_holds(&s100, &global->stack_a, index);
		chunk_phase(&s100, global, index);
		if (s100.chnk_count == s100.chnk_max_count)
			get_next_chunk(&s100, &global->stack_a);
	}
	i = -1;
	while (++i < (int)global->stack_b.size)
		printf("STACK_B[%d]: %d\n", i, global->stack_b.array[i]);
	/*while (global->stack_b.size != 0)
	{
		place_top(&s100, &global->stack_b);
		push_b_phase(&s100, global);
	}*/
	i = -1;
	while (++i < (int)global->stack_a.size)
		printf("STACK_A[%d]: %d\n", i, global->stack_a.array[i]);
	return (0);
}

void	get_next_chunk(t_program *s100, t_stack *stack_a)
{
	s100->chnk_stack++;
	s100->chnk_max_count = (stack_a->max_size / s100->chnk_max_stack)
		* s100->chnk_stack;
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
	else if (global->stack_a.max_size >= 500)
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

void	simple_indexation(t_program *s100, t_stack *stack_a, int *index)
{
	size_t	i;
	size_t	j;
	int		lw_nb;

	lw_nb = s100->low_nb;
	j = 0;
	while (lw_nb != s100->high_nb + 1)
	{
		i = 0;
		while (i < stack_a->size)
		{
			if (stack_a->array[i] == lw_nb)
			{
				index[i] = j;
				j++;
			}
			i++;
		}
		lw_nb++;
	}
}

void	get_holds(t_program *s100, t_stack *stack, int *index)
{
	size_t	i;
	size_t	mid;
	int		status;

	mid = stack->size / 2;
	i = 0;
	while (i < mid && status == 0)
	{
		if (index[i] < (int)s100->chnk_max_stack)
		{
			s100->hold_first = i;
			status = 1;
		}
		i++;
	}
	status = 0;
	i = stack->size;
	while (i > mid && status == 0)
	{
		if (index[i] < (int)s100->chnk_max_stack)
		{
			s100->hold_second = i - mid;
			status = 1;
		}
		i--;
	}
}
