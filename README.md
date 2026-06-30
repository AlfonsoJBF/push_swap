COMANDO PARA EJECUTAR CON NUMEROS ALEATORIOS

> shuf -i 0-9999 -n 100 > args.txt ; ./push_swap $(cat args.txt)

COMANDO PARA ENVIAR STDERR A UN ARCHIVO

> ./push_swap 16 13 15 11 12 6 9 14 8 10 1 5 3 2 4 2> err.txt

Si cambiamos 2 por 1 enviara los movimientos a un archivo de texto, podria ser util para pasarle los movimientos a un visualizer
