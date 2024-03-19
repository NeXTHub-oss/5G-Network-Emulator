/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 */

#pragma once

#include <type_traits>

//--------------------------------------------------------------------------------------------------
// mean_handler(): templated class used for mean calculation used for data logging. 
//--------------------------------------------------------------------------------------------------
template<typename T>
class mean_handler
{
public: 
    mean_handler()
    {
        static_assert((std::is_same<float, T>::value ||
                    std::is_same<double, T>::value ||
                    std::is_same<int, T>::value), "You can't use anything different from float, double and int here");
    }

public: 
    void add(T v)
    { 
        value += v; 
        t_value += v; 
    }

    void step()
    {
        counter++; 
        total_value = (total_value*(total_counter - 1) + t_value)/total_counter; 
        t_value = 0;
        total_counter++; 
        
    }

    T get()
    {
        if(counter == 0) counter = 1; 
        float out_value = value/counter; 
        counter = 0;
        value = 0; 
        return out_value;
    }

    T get_total()
    {
        return total_value;
    }

private: 
    T value = 0; 
    T t_value = 0; 
    T total_value = 0; 
    int counter = 0; 
    int total_counter = 1; 
};