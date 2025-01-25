/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:23:52 by amait-ou          #+#    #+#             */
/*   Updated: 2025/01/25 11:01:18 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

int	pop_v(t_vector *vector)
{
	size_t	last;

	last = vector->size - 1;
	if (!empty_v(vector))
	{
		free(vector->vector[last]);
		vector->vector[last] = (void *)0x0;
		vector->size--;
		return (0);
	}
	return (1);
}
