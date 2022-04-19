#include <iostream>
#include <string>


using namespace std;


struct Stack
{
    char b;
    Stack* next;
};

void push(Stack*& stack, char val)
{
    Stack* newel = new Stack;
    newel->b = val;
    newel->next = stack;
    stack = newel;
}

bool pop(Stack*& stack, char& val)
{
    if (stack == nullptr)
        return false;

    val = stack->b;
    stack = stack->next;
}

bool peek(Stack* stack, char& val)
{
    if (stack == nullptr)
        return false;

    val = stack->b;
}

void print(Stack*& stack)
{
    char val;
    while (pop(stack, val))
        std::cout << val << std::endl;
}
const char* op_br = "([<{";
const char* cl_br = ")]>}";

int get_op_br_index(char b)
{
    for (int i = 0; i < strlen(op_br); i++)
        if (op_br[i] == b)
            return i;
}

int is_bracket(char c)
{
    for (int i = 0; i < strlen(op_br); i++)
        if (op_br[i] == c)
            return i + 1;

    for (int i = 0; i < strlen(cl_br); i++)
        if (cl_br[i] == c)
            return -(i + 1);

    return 0;
}
int check(const char* exp)
{
    Stack* brackets = nullptr;
    char val;
    int last_open_bracket = -1;

    for (size_t i = 0; i < strlen(exp); i++)
    {
        int b_type = is_bracket(exp[i]);

        if (b_type > 0) // open bracket
        {
            push(brackets, exp[i]);
            last_open_bracket = i;
        }

        else if (b_type < 0) // close bracket
            if (pop(brackets, val))
                if (cl_br[get_op_br_index(val)] != exp[i])
                    return i;
    }

    if (brackets != nullptr)
        return last_open_bracket;

    return 0;
}
int main()
{

    const char* exp = "{()}";
    int res = check(exp);

    if (res == 0)
        cout << "right" << endl;
    else
        cout << "not true: " << res << endl;

    return 0;
}
