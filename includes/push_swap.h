/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:32:06 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/22 00:59:31 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_stack
{
	int		*array;
	size_t	size;
	size_t	max_size;
}			t_stack;

typedef struct s_global
{
	t_stack	stack_a;
	t_stack	stack_b;
}			t_global;

/* stacks_fill.c */

int			check_duplicate(t_stack *stack_a, int nb);
int			fill_stack(char *ptr_av, t_stack *stack_a, size_t *stack_nb);
int			process_arg(int ac, char *av[], t_stack *stack_a);
size_t		stack_counter(int ac, char *av[]);
int			stacks_fill(int ac, char *av[], t_stack *stack_a, t_stack *stack_b);
char		*ft_strdup_char(const char *str, char stop);

/* operations.c operations_1.c*/
void		swap_sa(t_stack *stack_a);
void		swap_sb(t_stack *stack_b);
void		swap_pa(t_stack *stack_a, t_stack *stack_b);
void		swap_pb(t_stack *stack_b, t_stack *stack_a);
void		swap_ra(t_stack *stack_a);
void		swap_rb(t_stack *stack_b);
void		swap_rra(t_stack *stack_a);
void		swap_rrb(t_stack *stack_b);

#endif