/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:23:19 by amait-ou          #+#    #+#             */
/*   Updated: 2025/01/25 11:01:10 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

void	*get_v(t_vector *vector, size_t index)
{
	void	*value;

	if (index >= size_v(vector))
		return ((void *)0x00);
	value = vector->vector[index];
	return (value);
}
