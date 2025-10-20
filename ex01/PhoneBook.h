/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 01:01:57 by oait-si-          #+#    #+#             */
/*   Updated: 2025/10/20 16:07:07 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H


#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.h"

class   PhoneBook
{
     
   private:
        Contact contacts[8];
        int count;
        int nextIndex;
   public:
        PhoneBook();
        void        add_infos(void);
        void        get_infos(void);
        
};

#endif