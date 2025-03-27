/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:20:52 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 15:26:35 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BRAIN_HPP_
# define _BRAIN_HPP_

# include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        virtual ~Brain();
        Brain( Brain const& copy );
        Brain& operator=( const Brain& other );

        void setIdea( int index, const std::string& idea );
        std::string getIdea( int index ) const;
};

#endif