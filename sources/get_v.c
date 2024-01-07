/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:23:19 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/07 18:33:11 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

void	*__get_v(t_vector *vector, size_t index)
{
	void	*__value;

	if (index >= __size_v(vector))
		return ((void *)0x00);
	__value = vector->vector[index];
	return (__value);
}
