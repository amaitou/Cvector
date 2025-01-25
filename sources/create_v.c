/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:22:06 by amait-ou          #+#    #+#             */
/*   Updated: 2025/01/25 11:00:36 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

t_vector	*create_v(void)
{
	t_vector	*v;

	v = (t_vector *)malloc(sizeof(t_vector));
	if (!v)
		return ((void *)0x00);
	v->capacity = 5;
	v->size = 0;
	v->vector = (void **)malloc(sizeof(void *) * v->capacity);
	memset(v->vector, 0, v->capacity);
	v->vector[v->size] = (void *)0x00;
	if (!v->vector)
		return ((void *)0x00);
	return (v);
}
