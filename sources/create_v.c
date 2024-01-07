/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:22:06 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/07 18:32:53 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

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
