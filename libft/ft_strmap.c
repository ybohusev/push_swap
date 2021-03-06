/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:30:27 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/15 16:30:28 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	j;

	j = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = (char*)malloc(ft_strlen((char*)s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[j])
	{
		str[j] = (*f)(s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
