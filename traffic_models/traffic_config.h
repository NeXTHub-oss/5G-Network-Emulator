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

#ifndef T_DL
#define T_DL 0
#endif
#ifndef T_UL
#define T_UL 1
#endif

#define CONSTANT_TRAFFIC_MODEL 0
//--------------------------------------------------------------------------------------------------
// traffic_config(): struct storing all the configuration information related with the traffic
// generator models. 
// Input: 
//      id: unique id of the UE used to initialize the random generator's seed. 
//      type: id of the traffic generator model which was selected for the current UE.
//      _ul_target/_dl_target: target throughput for UL and DL respectively. 
//      _var_perc: size of the variance of the generated noise. 
//      _pkt_size: virtual IP packet size in bits.
//--------------------------------------------------------------------------------------------------
struct traffic_config
{
    traffic_config(){}
    traffic_config(int _type, float _ul_target, float _dl_target, std::string _ul_traffic_file, std::string _dl_traffic_file, float _var_perc,
                    int _pkt_size, float _bh_d, float _bh_d_var, float _delay = 0)
                    {
                        type = _type; 
                        ul_target = _ul_target; 
                        dl_target = _dl_target; 
                        ul_traffic_file = _ul_traffic_file; 
                        dl_traffic_file = _dl_traffic_file; 
                        var_perc = _var_perc; 
                        pkt_size = _pkt_size; 
                        delay = _delay;
                    }
    int type; 
    float ul_target; 
    float dl_target;
    std::string dl_traffic_file;
    std::string ul_traffic_file;  
    float var_perc; 
    int pkt_size;
    float delay; 
    bool random_v=true; 
};