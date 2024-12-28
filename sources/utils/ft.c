/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:48:23 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/23 20:52:01 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*ft_malloc(size_t nbyte, size_t cnt)
{
	void	*ptr;

	ptr = (void *)malloc(nbyte * cnt);
	if (!ptr)
		return (NULL);
	return (ptr);
}