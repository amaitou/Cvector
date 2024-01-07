/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_v.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:25:37 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/07 18:33:07 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

void	*__front_v(t_vector *vector)
{
	if (!__empty_v(vector))
		return (vector->vector[0]);
	return ((void *)0x00);
}
