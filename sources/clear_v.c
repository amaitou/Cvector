/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_v.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:26:41 by amait-ou          #+#    #+#             */
/*   Updated: 2025/01/25 11:00:27 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cvector_v.h"

int	clear_v(t_vector *vector)
{
	if (empty_v(vector))
		return (1);
	while (!empty_v(vector))
		pop_v(vector);
	return (0);
}
