# NOTAS

***El proyecto entregado debe incluir los “logins” de ambas personas estudiantes en el repositorio.***

- La salida por consola debe ser la secuencia de operaciones necesarias
- Esta permitido el uso de la IA pero con cuidado
- La notación de nuestros algoritmos no refleja exactamente el tiempo o la memoria, si no la cantidad de movimientos.
- Hay que tener cuidado con los dos stacks y asegurarse que no hagan contacto y no se crucen:
    - si se mueven nodos de un stack a otro hay que vigilar los nodo->next
        al hacer push de a->b el nodo que estaba el primero solo cambia hacia quien apunta y se mueven los punteros
- para cambiarlo de un stack a otro hay que: guardar temporalmente el .next -> añadir el nodo actual al frente del otro stack -> mover el puntero inicial del stack original al que guardamos temporalmente

# DUDAS

- Formato de los parametros: debe ser un unico input o varios inputs? o una mezcla de ambas?
- El parseo y el programa se deben detener tras un error en el parseo?

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
- la complejidad es el numero de operaciones push_swap que deben realizarse, no la cantidad de tiempo de ejecucion del programa

## DESORDEN
- El desorden n(0-1) refleja lo lejos que esta el stack de ser ordenado al inicio del programa
- ordenado = 0
- todos los pares posibles desordenados = 1
- regla de 3: total = 100 / 1 = 1 -> n = (total * 0) / 100
calcular_desorden():
    errores, pares
    mientras i < tamaño del stack
        mientras 

# ROADMAP

1. implementar stacks y movimientos:
    - implementar logica del stack:
        - crear
        - intercambiar nodos
        - añadir nodo a una lista
    - implementar movimientos:


