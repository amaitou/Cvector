/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:27:08 by amait-ou          #+#    #+#             */
/*   Updated: 2025/01/25 10:59:37 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

t_vector	*allocate_v(size_t size)
{
	t_vector	*v;

	v = (t_vector *)malloc(sizeof(t_vector));
	if (!v)
		return ((void *)0x00);
	v->capacity = size + (size / 2);
	v->size = 0;
	v->vector = (void **)malloc(sizeof(void *) * v->capacity);
	memset(v->vector, 0, v->capacity);
	if (!v->vector)
		return ((void *)0x00);
	return (v);
}
