/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:51:28 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 13:43:58 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	unsigned char	d;

	if (c < 0 || c >= 255)
		return (0);
	d = (unsigned char)c;
	return ((d >= 'A' && d <= 'Z') || (d >= 'a' && d <= 'z') ||
			(d >= '0' && d <= '9') ? 1 : 0);
}