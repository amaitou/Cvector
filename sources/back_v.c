/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:26:02 by amait-ou          #+#    #+#             */
/*   Updated: 2025/01/25 10:59:48 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

void	*back_v(t_vector *vector)
{
	if (!empty_v(vector))
		return (vector->vector[size_v(vector) - 1]);
	return ((void *)0x00);
}
