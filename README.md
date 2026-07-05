COMANDO PARA EJECUTAR CON NUMEROS ALEATORIOS

> shuf -i 0-9999 -n 100 > args.txt ; ./push_swap $(cat args.txt)

COMANDO PARA ENVIAR STDERR A UN ARCHIVO

> ./push_swap 16 13 15 11 12 6 9 14 8 10 1 5 3 2 4 2> err.txt

Si cambiamos 2 por 1 enviara los movimientos a un archivo de texto, podria ser util para pasarle los movimientos a un visualizer


## ERRORES ENCONTRADOS EN EL CAMINO
malloc(): invalid next size (unsorted)
push_swap: malloc.c:2617: sysmalloc: Assertion `(old_top == initial_top (av) && old_size == 0) || ((unsigned long) (old_size) >= MINSIZE && prev_inuse (old_top) && ((unsigned long) old_end & (pagesize - 1)) == 0)' failed.
zsh: IOT instruction (core dumped)  ./push_swap $(cat args.txt)