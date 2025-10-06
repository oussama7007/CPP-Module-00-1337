/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:38:41 by oait-si-          #+#    #+#             */
/*   Updated: 2025/10/04 12:53:20 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 

#ifndef CONTACT_H
#define CONTACT_H


# include <iostream>
# include <string>

class Contact
{
    private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    public:
    void set_contact();
    void display_short(int index);
    void display_full();
    bool is_empty();
};

#endif