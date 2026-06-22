# Arquitectura general

> Dividimos el programa en capas segun el principio de **responsabilad única**


Si modificamos una parte no se rompen las demás
```
┌─────────────────────┐
│       MAIN          │ 
├─────────────────────┤
│     STACK ENGINE    │
├─────────────────────┤
│       PARSING       │
├─────────────────────┤
│      OPERATIONS     │
├─────────────────────┤
│     ALGORITHM       │
└─────────────────────┘
```
## MAIN
Es el hilo principal del programa.

Solo coordina, ni decide ni tiene lógica.

Debe de poder leerse y entender todo el flujo del programa.


## STACK ENGINE
Representacion y manipulación de las estructuras de datos. 
Seria como el apartado de las linked lists en la libft

### Responsabilidades
- Definir los tipos de datos posibles
- Definir los metodos para manipular estos datos
	- Intercambiar dos elementos
	- como modificar sus contenidos
	- crear nodos
	- eliminar y liberar nodos
### Prohibiciones
- No define los movimientos permitidos
- No calcula ni normaliza valores

## PARSING
Transforma y normaliza los argumentos recibidos y los devuelve con un formato adecuado.

### Responsabilidades
- Validar argumentos
	- dato numerico
	- no duplicado
	- detectar overflows o underflows
- Genera los nuevos nodos y los añade al final del stack A
### Prohibiciones
- Nunca intenta ordenar la lista
- No calcula valores lógicos

## OPERATIONS
Esta separado del stack por que conceptualmente son distintos, se apoyan en el engine y definen los movimientos permitidos en el proyecto.
### responsabilidades
- Define los movimientos permitidos para los algoritmos

## ALGORITHM

Es donde esta todo el desarrollo lógico de las operaciones.
Decide que debe ejecutar

***Debe poder forzarse a usar un algoritmo especifico***

El sabe que: existen las pilas y las operaciones

# Sistema de carpetas
```
push_swap/
│
├── Makefile
├── include/
│   ├── push_swap.h
│   ├── stack.h
│   ├── parser.h
│   ├── operations.h
│   ├── algorithm.h
│   └── error.h
│
├── src/
│   ├── main/
│   │   └── main.c
│   │
│   ├── parser/
│   │   ├── parser.c
│   │   ├── validation.c
│   │   ├── duplicates.c
│   │   └── normalization.c
│   │
│   ├── stack/
│   │   ├── stack_init.c
│   │   ├── stack_utils.c
│   │   ├── stack_free.c
│   │   └── stack_size.c
│   │
│   ├── operations/
│   │   ├── swap.c
│   │   ├── push.c
│   │   ├── rotate.c
│   │   └── reverse_rotate.c
│   │
│   ├── algorithm/
│   │   ├── sort_small.c
│   │   ├── radix.c
│   │   ├── cost.c
│   │   ├── target.c
│   │   ├── move.c
│   │   └── algorithm.c
│   │
│   ├── utils/
│   │   ├── ft_error.c
│   │   └── ft_exit.c
│   │
│   └── checker_bonus/
│       ├── checker.c
│       └── checker_utils.c
│
├── tests/
│
├── docs/
│   ├── roadmap.md
│   ├── algorithms.md
│   └── notes.md
│
└── libft/
```

# CORE LOOP

programa parametros:
	parsear los datos
	levantar dos stacks
	llenar stack a con los datos
	iniciar la resolucion:
		calcular tamaño
		calcular desorden
		elegir algoritmo
		ejecutar algoritmo