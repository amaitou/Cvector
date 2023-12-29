/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __cvector_utils___.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:31:28 by amait-ou          #+#    #+#             */
/*   Updated: 2023/12/29 02:35:02 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__cvector_.h"

int	__clear_v(t_vector *vector)
{
	size_t	i;

	i = 0;
	if (__empty_v(vector))
		return (1);
	while (i < __size_v(vector))
	{
		free(vector->vector[i]);
		vector->vector[i] = NULL;
		vector->size--;
	}
	return (0);
}
