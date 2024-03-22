/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:47:07 by jyap              #+#    #+#             */
/*   Updated: 2023/11/01 13:47:25 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int i, size_t size)
{
	char	*p;

	if (!s)
		return (s);
	p = (char *)s;
	while (size > 0)
	{
		p[size - 1] = i;
		size--;
	}
	return (s);
}