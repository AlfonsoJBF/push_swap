# NOTAS

***El proyecto entregado debe incluir los “logins” de ambas personas estudiantes en el repositorio.***

- La salida por consola debe ser la secuencia de operaciones necesarias
- Esta permitido el uso de la IA pero con cuidado
- La notación de nuestros algoritmos no refleja exactamente el tiempo o la memoria, si no la cantidad de movimientos.

# MOVIMIENTOS
- sa y sb
    Localizar segundo nodo
    guardar a donde apunta
    almacenar valores nodo 1 y dos
    añadir al frente en orden invertido
- ss
    ejecutar los dos s anteriores
- pa/pb
    Nuevo nodo copia del primero del stack
    insertar al frente en el nuevo stack
    almacenar la direccion del siguiente
    eliminar el nodo
    el puntero a la lista que apunte al nuevo primer nodo
- rotar:
    hacer un sistema de cola:
        el primero de todos sale
        entra por el fondo una copia

    hacer sistema de cola invertida (pop)
        sale el ultimo
        entra al frente una copia

# REQUISITOS ALGORITMO
Los algoritmos deben: analizar la entrada y generar la secuencia de operaciones adecuada
## COMPLEJIDAD Y RESTRICCIONES
- la complejidad es el numero de operaciones push_swap que deben realizarse

## DESORDEN
- El desorden n(0-1) refleja lo lejos que esta el stack de ser ordenado al inicio del programa
- ordenado = 0
- todos los pares posibles desordenados = 1
- regla de 3: total = 100 / 0 = 0 -> n = (total * 0) / 100
calcular_desorden():
    errores, pares
    mientras i < tamaño del stack
        mientras 

# ROADMAP

1. implementar stacks y movimientos:
    - cada uno podemos hacer una mitad de los movimientos -> push o swap
