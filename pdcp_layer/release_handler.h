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

#include <random>
#include <deque>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <utils/conversions.h>
#include <utils/logging/mean_handler.h>
#include <pdcp_layer/ip_buffer.h>
#include <netfilter/pkt_capture.h>

//--------------------------------------------------------------------------------------------------
// release_handler(): this class stores the packets which were determined to be released by the 
// emulator. They remove the packets from memory. 
// Input: 
//      _verbosity: Enable/disable verbosity
//--------------------------------------------------------------------------------------------------
class release_handler
{
public: 
    release_handler();
    ~release_handler();
    float release_one();
    void init();
    void quit();
    virtual void set_pkt_cptr(const std::shared_ptr<pkt_capture> &_pkt_cptr){}
    virtual void push(harq_pkt pkt);
    virtual void drop(harq_pkt pkt){}
    int get_size();
    virtual float release();
    void step(float t);
    void release_thread();

    float get_ip_latency(bool elapsed = true);
    float get_latency(bool elapsed = true);
    float get_tp(bool elapsed = true);

protected: 
    bool check_order(int id);
    void update_order(int id);


protected: 
    int prev_id = -1; 

protected: 
    std::deque<harq_pkt> pkt_list; 
    float current_t = 0; 
    bool is_awake = false; 

protected: 
    mean_handler<float> tp_mean; 
    mean_handler<float> l_mean; 
    mean_handler<float> ipl_mean; 

protected: 
    std::mt19937 gauss_dist_gen;
    std::uniform_real_distribution<float> gauss_dist{-1,1};
};