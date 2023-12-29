/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __cvector_utils__.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 06:05:57 by amait-ou          #+#    #+#             */
/*   Updated: 2023/12/29 03:22:06 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__cvector_.h"

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
		vector->vector[i] = NULL;
		++i;
	}
	free(vector->vector);
	free(vector);
}

int	__empty_v(t_vector *vector)
{
	return (!vector->size);
}

void	*__front_v(t_vector *vector)
{
	if (!__empty_v(vector))
		return (vector->vector[0]);
	return (NULL);
}

void	*__back_v(t_vector *vector)
{
	if (!__empty_v(vector))
		return (vector->vector[__size_v(vector) - 1]);
	return (NULL);
}
