/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_v.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:25:37 by amait-ou          #+#    #+#             */
/*   Updated: 2025/01/25 11:01:03 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

void	*front_v(t_vector *vector)
{
	if (!empty_v(vector))
		return (vector->vector[0]);
	return ((void *)0x00);
}
