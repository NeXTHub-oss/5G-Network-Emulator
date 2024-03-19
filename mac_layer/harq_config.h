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

//--------------------------------------------------------------------------------------------------
// pdcp_config(): HARQ configuration struct
// Input: 
//              *mod: 0 - 64 QAM | 1 - 256 QAM
//              *layers: Number of MIMO layers. 
//              *log_units: number of RBs per RBG group. 
//--------------------------------------------------------------------------------------------------
struct harq_config
{
    harq_config(int _mod, int _layers, int _log_units)
    {
        mod = _mod; 
        layers = _layers; 
        log_units = _log_units; 
    }
    int mod; 
    int layers; 
    int log_units; 
};