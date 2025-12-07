/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:08:56 by thribeir          #+#    #+#             */
/*   Updated: 2025/12/07 17:19:54 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# include <limits.h>

# define MAX_OPS 200000
# define ERROR_MSG "Error\n"

typedef struct s_stack
{
	int	*data;
	int	cap;
	int	size;
	int	head;
}	t_stack;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_ctx
{
	t_stack		a;
	t_stack		b;
	t_op		ops[MAX_OPS];
	int			op_len;
}	t_ctx;

typedef struct s_move_cost
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	total;
	int	index_b;
}	t_move_cost;

typedef struct s_abinfo
{
	int	up_a;
	int	down_a;
	int	up_b;
	int	down_b;
}	t_abinfo;

int		stack_at(const t_stack *s, int i);
void	stack_set(t_stack *s, int i, int value);
void	push_front(t_stack *s, int value);
void	push_back(t_stack *s, int value);
int		pop_front(t_stack *s);
int		pop_back(t_stack *s);
void	stack_init(t_stack *s, int size);
void	stack_free(t_stack *s);
int		stack_empty(t_stack *s);
void	print_stack(t_stack *s);
int		fill_stack(t_ctx *ctx, char *s);
void	just_debug(t_stack *s);
void	index_stack(t_stack *a);
int		is_sorted(t_stack *a);
int		*build_lis_keep(t_stack *a);
void	push_non_lis(t_ctx *ctx, int *keep);
void	rotate_a(t_ctx *ctx);
void	normalize_a(t_ctx *ctx);
int		find_target_index(t_stack *a, int x);
void	print_ops(t_ctx *ctx);
int		is_valid_int(const char *s);
int		has_duplicates(t_stack *s);
char	*join_args(int argc, char **argv);
int		get_min_index(t_stack *a);
void	insert_all_from_b(t_ctx *ctx);
void	apply_move(t_ctx *ctx, t_move_cost *move);
void	compute_best_pattern(t_move_cost *cand, t_abinfo *ab);
void	sort_upto_five(t_ctx *ctx);
void	op_pa(t_ctx *ctx);
void	op_pb(t_ctx *ctx);
void	op_sa(t_ctx *ctx);
void	op_sb(t_ctx *ctx);
void	op_ra(t_ctx *ctx);
void	op_rb(t_ctx *ctx);
void	op_rr(t_ctx *ctx);
void	op_rra(t_ctx *ctx);
void	op_rrb(t_ctx *ctx);
void	op_rrr(t_ctx *ctx);

#endif
