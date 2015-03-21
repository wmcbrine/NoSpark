// NoSpark - OpenEVSE charger firmware
// Copyright (C) 2015 Andre Eisenbach
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// See LICENSE for a copy of the GNU General Public License or see
// it online at <http://www.gnu.org/licenses/>.

#pragma once

#include "board/j1772status.h"
#include "utils/cpp.h"
#include "settings.h"

namespace evse
{

class State
{
    State();

public:
    enum ControllerState
    {
        BOOTUP
      , POST
      , RUNNING
      , FAULT
    };

    enum ControllerFault
    {
        NOTHING_WRONG
      , FAULT_POST_GFCI
      , FAULT_POST_RELAY
      , FAULT_GFCI_TRIPPED
    };

    static State& get();

    ControllerState controller;
    ControllerFault fault;
    board::J1772Status::J1772State j1772;

private:
    DISALLOW_COPY_AND_ASSIGN(State);
};

}