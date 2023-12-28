/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __cvector_utils__.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 06:05:57 by amait-ou          #+#    #+#             */
/*   Updated: 2023/12/28 06:06:03 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector.h"

size_t	__size_v(t_vector *vector)
{
	return (vector->size);
}

void	__free_v(t_vector *vector)
{
	size_t	i;

	i = 0;
	while (i < __size_v(vector))
	{
		free((vector)->vector[i]);
		++i;
	}
	free(vector->vector);
	free(vector);
}

int	__empty_v(t_vector *vector)
{
	return (vector->size);
}
