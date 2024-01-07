/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:23:52 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/07 18:33:15 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

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
