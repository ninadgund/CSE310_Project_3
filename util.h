
#pragma once

#include <cstring>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

//Util class for utility functions
namespace Module
{
    // Enum classes for queries
    enum class Temp
    {
        DEFAULT_NONE,
        TOTAL,
        MALE,
        FEMALE,
        ALL,
    };

    // Linked list of string data type
    struct StrArray
    {
        string str;
        StrArray * next;
    };

    // Pair of integers
    struct IntPair
    {
        int first;
        int second;
    };

    class util
    {
    private:
        /* data */
    public:
        util() = delete;
        ~util();

    };
}
