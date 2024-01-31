/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:29:15 by aherbin           #+#    #+#             */
/*   Updated: 2024/01/30 16:30:44 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include "libft.h"

//int	main()
//{
//	ft_printf("\033[38;5;42m\033[48;5;125m \
//███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n \
//████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n \
//██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n \
//██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n \
//██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n \
//╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n\033[0m");
//}
//static void	ft_print_header(int pid)
//{
//	ft_printf("\033[38;5;42m\n\
//                                                              \n \
//███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗ \n \
//████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝ \n \
//██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝  \n \
//██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗  \n \
//██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗ \n \
//╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ \n\033[0m");
//	ft_printf("\n\n  \033[38;5;42;4;3;1m\t\tPID: %i\t\
//by: aherbin\n\n\033[0m", pid);
//	ft_printf("\033[38;5;125m \
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
//}


#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<string.h>

int bin_to_char(int** ptr)
{
    static char  c;
    int    byte_idx;
    int    bit_idx;
    int    val;

    byte_idx = 0;
    printf("Value per 8 bit -> ");
    while (ptr[byte_idx])
    {
        bit_idx = 0;
        while (bit_idx < 8)
        {
           val = ptr[byte_idx][bit_idx];
           if (val == 1)
              c = (c << 1) | 1;
           else if (val == 0)
              c <<= 1;
           bit_idx++;
        }
        printf("%d : ", c);
        byte_idx++;
    }
    return (c);
}

int** char_to_bin(char* str)
{
    int** ptr;
    int  byte_index;
    int  bit_index;
    int  i;

    byte_index = 0;
    while (str[++byte_index]);
    ptr = calloc(byte_index + 1, sizeof(int*));
    if (!ptr)
      return(NULL);
    byte_index = 0;
    printf("Binary value -> ");
    while (str[byte_index])
    {
        ptr[byte_index] = calloc(sizeof(int), 8);
        if (!ptr[byte_index])
            return(NULL);
        bit_index = 7;
        i = 0;
        while (bit_index >= 0) {
           ptr[byte_index][i++] = (str[byte_index] >> bit_index) & 1;
           printf("%d -> %d\n", str[byte_index] >> bit_index, (str[byte_index] >> bit_index) & 1);
           bit_index--;
        }
        printf(" : ");
        byte_index++;
    }
    return (ptr);
}

int main(void) {
    char str[5] = "🌍"; // -16:-97:-116:-115 or 11110000 : 10011111 : 10001100 : 10001101
//   char str[2] = "H"; // 72 01001000
   int** ptr;
   int cc;

   ptr = char_to_bin(str);
    cc = bin_to_char(ptr);
   printf("\nhehe %i\n", cc);
   return (0);
}
