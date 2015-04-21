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

namespace utils
{

template <typename T>
const T& min(const T& a, const T& b)
{
    if (b < a)
        return b;
    return a;
}

template <typename T>
const T& max(const T& a, const T& b)
{
    if (b > a)
        return b;
    return a;
}

template <typename T, const T max_seed>
T square_root(T val)
{
    if (val < 2)
        return val;

    T min = 1;
    T max = max_seed;

    T test = 0;
    while (1)
    {
        test = (max - min) / 2 + min;

        if (max - min < 2)
          break;

        if ((test * test) > val)
            max = test;
        else
            min = test;
    }

    return test;
}

}
