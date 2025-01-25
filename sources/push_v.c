/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:22:35 by amait-ou          #+#    #+#             */
/*   Updated: 2025/01/25 11:01:25 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

static int	copy_v(t_vector *old_vector, t_vector *new_vector, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size_v(old_vector))
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

int	push_v(t_vector **vector, void *value, size_t size)
{
	t_vector	*v;

	v = (t_vector *)malloc(sizeof(t_vector));
	if (!v)
		return (1);
	if ((*vector)->size + 1 == (*vector)->capacity)
	{
		v->size = (*vector)->size;
		v->capacity = (*vector)->capacity * 2;
		v->vector = (void **)malloc(sizeof(void *) * v->capacity);
		if (!v->vector)
			return (1);
		if (!copy_v(*vector, v, size))
		{
			free_v(*vector);
			*vector = v;
		}
	}
	else
		free(v);
	(*vector)->vector[(*vector)->size] = value;
	(*vector)->size++;
	(*vector)->vector[(*vector)->size] = NULL;
	return (0);
}
