/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvector_v.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 07:43:55 by amait-ou          #+#    #+#             */
/*   Updated: 2025/01/25 10:59:20 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVECTOR_V_H
# define CVECTOR_V_H

# include <stdlib.h>
# include <string.h>

typedef struct s_vector
{
	size_t	size;
	size_t	capacity;
	void	**vector;
}	t_vector;

void		**begin_v(t_vector *vector);
void		**end_v(t_vector *vector);
t_vector	*create_v(void);
t_vector	*allocate_v(size_t size_t);
void		*get_v(t_vector *vector, size_t index);
void		*front_v(t_vector *vector);
void		*back_v(t_vector *vector);
void		free_v(t_vector *vector);
int			empty_v(t_vector *vector);
int			push_v(t_vector **vector, void *value, size_t size);
int			pop_v(t_vector *vector);
int			clear_v(t_vector *vector);
size_t		size_v(t_vector *vector);
size_t		capacity_v(t_vector *vector);

#endif
