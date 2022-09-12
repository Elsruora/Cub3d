/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:33:37 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/12 15:06:53 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}

int	ft_is_str_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}
