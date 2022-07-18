/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:34:15 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/18 10:07:28 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_ra(t_global *g)
{
	t_stack	*aux;
	t_stack	*tmp;

	if (ft_lstsize(g->a) < 1)
		return (1);
	tmp = g->a;
	aux = g->a->next;
	g->a = ft_lstlast(g->a);
	g->a->next = tmp;
	tmp->next = NULL;
	g->a = aux;
	return (0);
}

int	swap_rb(t_global *g)
{
	t_stack	*aux;
	t_stack	*tmp;

	if (ft_lstsize(g->b) < 1)
		return (1);
	tmp = g->b;
	aux = g->b->next;
	g->b = ft_lstlast(g->b);
	g->b->next = tmp;
	tmp->next = NULL;
	g->b = aux;
	return (0);
}

int	swap_rr(t_global *g)
{
	swap_ra(g);
	swap_rb(g);
	return (0);
}

int	swap_rra(t_global *g)
{
	t_stack	*aux;

	g->head_a = g->a;
	aux = g->a;
	aux = ft_lstlast(aux);
	ft_lstadd_front(g->head_a, aux);
	g->head_a = aux;
	while (g->a->next)
	{
		if (g->a->next->content == g->head_a->content)
			break ;
		g->a = g->a->next;
	}
	g->a->next = NULL;
	g->a = g->head_a;
}
