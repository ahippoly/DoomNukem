/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:21:28 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/19 17:04:41 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *haystack, char *needle)
{
	int i;
	int j;

	if (*needle == 0)
		return (haystack);
	while (*haystack != 0)
	{
		i = 0;
		j = 0;
		while (*haystack != *needle && *haystack != 0)
			haystack++;
		while (needle[j] == haystack[i++] && needle[j] != 0)
			j++;
		if (*haystack == 0)
			return (0);
		else if (needle[j] == 0)
			return (haystack);
		haystack++;
	}
	return (0);
}
