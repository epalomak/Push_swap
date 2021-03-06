/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:18:36 by epalomak          #+#    #+#             */
/*   Updated: 2021/04/29 16:10:58 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/printf/headers.h"
# include <limits.h>

typedef struct	s_ps
{
	int			ac;
	int			*st_a;
	int			*st_b;
	int			size_a;
	int			size_b;
	int			print_it;
	struct s_ps	*next;

}				t_ps;

void			swap(t_ps *ps, char *cmd);
void			push(t_ps *ps, char *cmd);
void			rotate(t_ps *ps, char *cmd);
void			rev_rotate(t_ps *ps, char *cmd);
void			display_errors(void);
void			sort(t_ps *ps);
void			sort_three(t_ps *ps);
void			sort_five(t_ps *ps);
void			sort_all(t_ps *ps);
void			rb_rrb_x_times(t_ps *ps, int pos);
void			back_to_a(t_ps *ps);
int				check_stack(t_ps *ps);
int				check_final(t_ps *ps);
int				*get_numbers(t_ps *ps, char **av);
int				highest_elem(int *stack, int stack_size);
int				lowest_elem(int *stack, int stack_size);

#endif
