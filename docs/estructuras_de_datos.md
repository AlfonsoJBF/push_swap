```C
// NODES
typedef struct s_node
{
    int             value;
    int             index;
    int             pos;
    int             target_pos;

    struct s_node   *next;
}   t_node;
// STACKS
typedef struct s_stack
{
    t_node  *a;
    t_node  *b;

    int     size_a;
    int     size_b;
}   t_stack;
```