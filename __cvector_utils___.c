/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __cvector_utils___.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:31:28 by amait-ou          #+#    #+#             */
/*   Updated: 2023/12/29 08:54:43 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__cvector_.h"

int	__clear_v(t_vector *vector)
{
	size_t	i;

	i = 0;
	if (__empty_v(vector))
		return (1);
	while (!__empty_v(vector))
		__pop_v(vector);
	return (0);
}

t_vector	*__allocate_v(size_t size)
{
	t_vector	*__v;

	__v = (t_vector *)malloc(sizeof(t_vector));
	if (!__v)
		return ((void *)0x00);
	__v->capacity = size + (size / 2);
	__v->size = 0;
	__v->vector = (void **)malloc(sizeof(void *) * __v->capacity);
	memset(__v->vector, 0, __v->capacity);
	if (!__v->vector)
		return ((void *)0x00);
	return (__v);
}

size_t	__capacity_v(t_vector *vector)
{
	return (vector->capacity);
}

void	**__begin_v(t_vector *vector)
{
	void	**__begin;

	__begin = vector->vector + 0x00;
	return (__begin);
}

void	**__end_v(t_vector *vector)
{
	void	**__end;

	__end = vector->vector[__size_v(vector)];
	return (__end);
}
