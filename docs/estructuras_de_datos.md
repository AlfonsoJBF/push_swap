```C
// NODES
typedef struct s_node
{
    int             value; //nº
    int             index; // posicion del valor dentro del conjunto ordenado para Radix
    int             pos; // posicion actual
    int             target_pos; // a que posicion se debe insertar

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

| Campo        | Qué representa    | Quién lo mantiene | Tipo                |
| ------------ | ----------------- | ----------------- | ------------------- |
| `value`      | valor original    | parser            | permanente          |
| `index`      | rango normalizado | normalización     | permanente derivado |
| `pos`        | posición actual   | algoritmo         | temporal            |
| `target_pos` | destino ideal     | algoritmo?        | temporal            |
| `next`       | enlace lista      | stack engine      | infraestructura     |
| `a`          | top de A          | operations        | estado global       |
| `b`          | top de B          | operations        | estado global       |
| `size_a`     | tamaño A          | operations        | caché               |
| `size_b`     | tamaño B          | operations        | caché               |
