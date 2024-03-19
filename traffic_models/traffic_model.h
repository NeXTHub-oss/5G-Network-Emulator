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

#ifndef TRAFFIC_MODEL_H
#define TRAFFIC_MODEL_H

#include <traffic_models/traffic_model_base.h>
#include <traffic_models/traffic_generator.h>
//--------------------------------------------------------------------------------------------------
// traffic_model(): class which selects the traffic generator model which will be used to generate
// virtual bits for simulated users. 
// Input: 
//      id: unique id of the UE used to initialize the random generator's seed. 
//      type: id of the traffic generator model which was selected for the current UE.
//      _ul_target/_dl_target: target throughput for UL and DL respectively. 
//      _var_perc: size of the variance of the generated noise. 
//      _pkt_size: virtual IP packet size in bits.
//--------------------------------------------------------------------------------------------------
class traffic_model
{
public:
    traffic_model( int id, traffic_config traffic_c)
    {
        traffic_c.ul_target = traffic_c.ul_target*MBIT2BIT;
        traffic_c.dl_target = traffic_c.dl_target*MBIT2BIT;
        if(traffic_c.type == CONSTANT_TRAFFIC_MODEL)
        {
            traff_model = std::unique_ptr<traffic_model_base>(new traffic_model_base(id, traffic_c.ul_target, traffic_c.dl_target, traffic_c.var_perc, traffic_c.pkt_size, traffic_c.random_v));
        }
        else if(traffic_c.type == TRAFFIC_GENERATOR_MODEL)
        {
            traff_model = std::unique_ptr<traffic_model_base>(new traffic_generator(id, traffic_c.ul_traffic_file, traffic_c.dl_traffic_file, traffic_c.pkt_size, traffic_c.delay));
        }
        else
        {
            traff_model = std::unique_ptr<traffic_model_base>(new traffic_model_base(id, traffic_c.ul_target, traffic_c.dl_target, traffic_c.var_perc, traffic_c.pkt_size, traffic_c.random_v));
        }
    }

public:
    float generate(int tx, double t)
    {
        return traff_model->generate(tx, t);
    }

    int get_pkt_size(int tx)
    {
        return traff_model->get_pkt_size(tx);
    }

private: 
    std::unique_ptr<traffic_model_base> traff_model; 
};

#endif
