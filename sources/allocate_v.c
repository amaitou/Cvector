/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:27:08 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/07 18:32:13 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

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
