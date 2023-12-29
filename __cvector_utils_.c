/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __cvector_utils_.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 06:06:31 by amait-ou          #+#    #+#             */
/*   Updated: 2023/12/29 08:55:31 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__cvector_.h"

t_vector	*__create_v(void)
{
	t_vector	*__v;

	__v = (t_vector *)malloc(sizeof(t_vector));
	if (!__v)
		return ((void *)0x00);
	__v->capacity = 5;
	__v->size = 0;
	__v->vector = (void **)malloc(sizeof(void *) * __v->capacity);
	memset(__v->vector, 0, __v->capacity);
	__v->vector[__v->size] = (void *)0x00;
	if (!__v->vector)
		return ((void *)0x00);
	return (__v);
}

int	__copy_v(t_vector *old_vector, t_vector *new_vector, size_t size)
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

void	*__get_v(t_vector *vector, size_t index)
{
	void	*__value;

	if (index >= __size_v(vector))
		return ((void *)0x00);
	__value = vector->vector[index];
	return (__value);
}

int	__pop_v(t_vector *vector)
{
	size_t	__last;

	__last = vector->size - 1;
	if (!__empty_v(vector))
	{
		free(vector->vector[__last]);
		vector->vector[__last] = (void *)0x0;
		vector->size--;
		return (0);
	}
	return (1);
}
