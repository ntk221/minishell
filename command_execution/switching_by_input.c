/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switching_by_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:44:06 by satushi           #+#    #+#             */
/*   Updated: 2022/12/25 21:21:26 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool echo_or_not(char *sub)
{
	int		sublen;
	char	*echo;

	sublen = strlen(sub);
	echo = "echo";
	if (sublen != 4)
		return false;
	while (sublen != 0)
	{
		if (sub[sublen] != echo[sublen])
			return false;
		sublen--;
	}
	return (true);
}

void obtain_commandinfo(char **input_string_all, int *inputstringposition)//, int separatednum
{
	if (true == echo_or_not(input_string_all[*inputstringposition]))
		echo_branch(input_string_all, inputstringposition); // echo の 引数の有無を判定して処理に回す
	return ;
}