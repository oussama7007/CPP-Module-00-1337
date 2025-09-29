/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:20:35 by oait-si-          #+#    #+#             */
/*   Updated: 2025/09/29 11:30:11 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char *av[])
{
       if(ac >= 2)
        {
            for(int j = 1; j < ac; j++)
            {
                for(int i = 0; av[j][i]; i++)
                {
                    if(av[j][i] >= 'a' && av[j][i] <= 'z')
                        av[j][i] = std::toupper(av[j][i]);
                    std::cout << av[j][i];
                } 
            }
        }
        else 
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        std::cout << '\n';
}


/// it should rewrite in the c++ manner 