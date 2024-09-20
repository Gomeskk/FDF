/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:47:24 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/29 00:24:02 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int main() {
    char character = 'A';
    int file_descriptor = STDOUT_FILENO; 
	// File descriptor for standard output (stdout)
    ft_putchar_fd(character, file_descriptor);
	printf("\n");
    return 0;
} */
/* Outputs the character ’c’ to the given file
descriptor. */