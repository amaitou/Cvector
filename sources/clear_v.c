/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_v.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:26:41 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/07 18:32:49 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

int	__clear_v(t_vector *vector)
{
	if (__empty_v(vector))
		return (1);
	while (!__empty_v(vector))
		__pop_v(vector);
	return (0);
}
