/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:26:02 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/07 18:32:33 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

void	*__back_v(t_vector *vector)
{
	if (!__empty_v(vector))
		return (vector->vector[__size_v(vector) - 1]);
	return ((void *)0x00);
}
