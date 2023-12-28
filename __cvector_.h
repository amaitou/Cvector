/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvector.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 07:43:55 by amait-ou          #+#    #+#             */
/*   Updated: 2023/12/28 06:09:14 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVECTOR_H
# define CVECTOR_H

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
int			__empty_v(t_vector *vector);
void		__free_v(t_vector *vector);
size_t		__size_v(t_vector *vector);
void		__print_v(t_vector *vector);
void		__copy_v(t_vector *old_vector, t_vector *new_vector, size_t size);
void		*__push_v(t_vector **vector, void *value, size_t size);

#endif