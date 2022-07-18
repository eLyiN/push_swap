/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:54:03 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/18 10:06:11 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_sa(t_global *g)
{
	t_stack	*aux;

	aux = g->a;
	g->head_a = g->a;
	if (ft_lstsize(g->a) < 1)
		return (1);
	g->a = g->a->next->next;
	g->head_a = g->head_a->next;
	aux->next = NULL;
	g->head_a->next = aux;
	g->head_a->next->next = g->a;
	g->a = g->head_a;
	return (0);
}

int	swap_sb(t_global *g)
{
	t_stack	*aux;

	aux = g->b;
	g->head_b = g->b;
	if (ft_lstsize(g->b) < 1)
		return (1);
	g->b = g->b->next->next;
	g->head_b = g->head_b->next;
	aux->next = NULL;
	g->head_b->next = aux;
	g->head_b->next->next = g->b;
	g->b = g->head_b;
	return (0);
}

int	swap_ss(t_global *g)
{
	swap_sa(g);
	swap_sb(g);
	return (0);
}

int	swap_pa(t_global *g)
{
	t_stack	*aux;

	if (ft_lstsize(g->b) < 1)
		return (1);
	aux = g->b;
	g->b = g->b->next;
	aux->next = g->a;
	g->a = aux;
	return (0);
}

int	swap_pb(t_global *g)
{
	t_stack	*aux;

	if (ft_lstsize(g->a) < 1)
		return (1);
	aux = g->a;
	g->a = g->b->next;
	aux->next = g->b;
	g->b = aux;
	return (0);
}

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
	t_stack *aux;

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