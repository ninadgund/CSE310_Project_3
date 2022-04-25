
#pragma once

#include "StackNode.h"

//Stack module for SCC
namespace Module
{
    class Stack
    {
    private:
        /* data */
        StackNode * head;
    public:
        Stack();
        ~Stack();

        void push(int i);
        int pop();
        int top();
        bool empty();

    };
}
