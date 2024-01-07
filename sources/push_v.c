/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:22:35 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/07 18:33:18 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

static int	__copy_v(t_vector *old_vector, t_vector *new_vector, size_t size)
{
	size_t	i;

	i = 0;
	while (i < __size_v(old_vector))
	{
		new_vector->vector[i] = (void *)malloc(size);
		if (!new_vector->vector[i])
			return (1);
		memset(new_vector->vector[i], 0, size);
		memcpy(new_vector->vector[i], old_vector->vector[i], size);
		++i;
	}
	return (0);
}

int	__push_v(t_vector **vector, void *value, size_t size)
{
	t_vector	*__v;

	__v = (t_vector *)malloc(sizeof(t_vector));
	if (!__v)
		return (1);
	if ((*vector)->size + 1 == (*vector)->capacity)
	{
		__v->size = (*vector)->size;
		__v->capacity = (*vector)->capacity * 2;
		__v->vector = (void **)malloc(sizeof(void *) * __v->capacity);
		if (!__v->vector)
			return (1);
		if (!__copy_v(*vector, __v, size))
		{
			__free_v(*vector);
			*vector = __v;
		}
	}
	else
		free(__v);
	(*vector)->vector[(*vector)->size] = value;
	(*vector)->size++;
	(*vector)->vector[(*vector)->size] = NULL;
	return (0);
}
