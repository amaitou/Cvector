/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __cvector_.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 07:43:55 by amait-ou          #+#    #+#             */
/*   Updated: 2023/12/29 04:52:14 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CVECTOR__H
# define __CVECTOR__H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_vector
{
	size_t	size;
	size_t	capacity;
	void	**vector;
}	t_vector;

t_vector	*__create_v(void);
t_vector	*__allocate_v(size_t size_t);
int			__empty_v(t_vector *vector);
void		__free_v(t_vector *vector);
size_t		__size_v(t_vector *vector);
int			__copy_v(t_vector *old_vector, t_vector *new_vector, size_t size);
int			__push_v(t_vector **vector, void *value, size_t size);
void		*__get_v(t_vector *vector, size_t index);
int			__pop_v(t_vector *vector);
void		*__front_v(t_vector *vector);
void		*__back_v(t_vector *vector);
int			__clear_v(t_vector *vector);
size_t		__capacity_v(t_vector *vector);
void		**__begin_v(t_vector *vector);

#endif
