
#include "Stack.h"
#include "util.h"

Module::Stack::Stack()
{
    head = nullptr;
}

Module::Stack::~Stack()
{
    while (!empty())
    {
        pop();
    }
}

void Module::Stack::push(int i)
{
    StackNode* temp = new StackNode(i, head);
    head = temp;
}

int Module::Stack::pop()
{
    if (empty())
    {
        return -1;
    }
    int ans = top();
    StackNode* temp = head;
    head = head->next;
    delete temp;
    return ans;
}

int Module::Stack::top()
{
    return head->index;
}

bool Module::Stack::empty()
{
    return (head == nullptr);
}
