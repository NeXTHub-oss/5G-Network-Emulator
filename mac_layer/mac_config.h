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

//
// MAC CONFIG
//
struct mac_config
{
    mac_config(int _mimo_layers, int _numerology, int _n_re_freq, int _n_ofdm_syms,int _bandwidth, int _scheduling_mode,
            int _scheduling_type, int _scheduling_config, int _metric_type, 
            int _duplexing_type)
    {
        mimo_layers = _mimo_layers; 
        numerology = _numerology; 
        n_re_freq = _n_re_freq; 
        n_ofdm_syms = _n_ofdm_syms; 
        bandwidth = _bandwidth; 
        scheduling_config = _scheduling_config; 
        scheduling_mode = _scheduling_mode;
        scheduling_type = _scheduling_type; 
        metric_type = _metric_type; 
        duplexing_type = _duplexing_type;
    }
    int mimo_layers; 
    int numerology; 
    int n_re_freq;
    int n_ofdm_syms;
    int bandwidth; 
    int scheduling_mode; 
    int scheduling_type; 
    int scheduling_config; 
    int metric_type; 
    int duplexing_type; 
};