/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __cvector_utils_.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 06:06:31 by amait-ou          #+#    #+#             */
/*   Updated: 2023/12/28 09:32:44 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__cvector_.h"

t_vector	*__create_v(void)
{
	t_vector	*__v;

	__v = (t_vector *)malloc(sizeof(t_vector));
	if (!__v)
		return (NULL);
	__v->capacity = 5;
	__v->size = 0;
	__v->vector = (void **)malloc(sizeof(void *) * __v->capacity);
	if (!__v->vector)
		return (NULL);
	return (__v);
}

void	__copy_v(t_vector *old_vector, t_vector *new_vector, size_t size)
{
	size_t	i;

	i = 0;
	while (i < __size_v(old_vector))
	{
		new_vector->vector[i] = (void *)malloc(size);
		if (!new_vector->vector[i])
			return ;
		memcpy(new_vector->vector[i], old_vector->vector[i], size);
		++i;
	}
}

void	*__push_v(t_vector **vector, void *value, size_t size)
{
	t_vector	*__v;

	__v = (t_vector *)malloc(sizeof(t_vector));
	if (!__v)
		return (NULL);
	if ((*vector)->size + 1 == (*vector)->capacity)
	{
		__v->size = (*vector)->size;
		__v->capacity = (*vector)->capacity * 2;
		__v->vector = (void **)malloc(sizeof(void *) * __v->capacity);
		if (!__v)
			return (NULL);
		__copy_v(*vector, __v, size);
		__free_v(*vector);
		*vector = __v;
	}
	else
		free(__v);
	(*vector)->vector[(*vector)->size] = value;
	(*vector)->size++;
	return ((void *)1);
}

void	*__get_v(t_vector *vector, size_t index)
{
	void	*__value;

	if (index >= __size_v(vector))
		return (NULL);
	__value = vector->vector[index];
	return (__value);
}
