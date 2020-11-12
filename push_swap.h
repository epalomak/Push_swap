/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:18:36 by epalomak          #+#    #+#             */
/*   Updated: 2020/11/12 14:41:41 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFF_SIZE 42
# define MAX_FD 4864

# include "../libft/libft.h"
# include "../libft/printf/headers.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_ps
{
	int			ac;
	int			*st_a;
	int			*st_b;
	struct s_ps	*next;
	
}				t_ps;


void	swap(t_ps *ps, char *cmd);
void	push(t_ps *ps, char *cmd);
void	rotate(t_ps *ps, char *cmd);
void	rev_rotate(t_ps *ps, char *cmd);
void	display_errors();
int		*get_numbers(t_ps *ps, char **av);
int		get_next_line(const int fd, char **line);

#endif