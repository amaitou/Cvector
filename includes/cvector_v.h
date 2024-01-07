/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvector_v.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 07:43:55 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/07 18:31:30 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVECTOR_V_H
# define CVECTOR_V_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_vector
{
	size_t	size;
	size_t	capacity;
	void	**vector;
}	t_vector;

void		**__begin_v(t_vector *vector);
void		**__end_v(t_vector *vector);
t_vector	*__create_v(void);
t_vector	*__allocate_v(size_t size_t);
void		*__get_v(t_vector *vector, size_t index);
void		*__front_v(t_vector *vector);
void		*__back_v(t_vector *vector);
void		__free_v(t_vector *vector);
int			__empty_v(t_vector *vector);
int			__push_v(t_vector **vector, void *value, size_t size);
int			__pop_v(t_vector *vector);
int			__clear_v(t_vector *vector);
size_t		__size_v(t_vector *vector);
size_t		__capacity_v(t_vector *vector);

#endif
