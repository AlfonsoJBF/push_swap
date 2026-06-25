# Movimientos permitidos

| Movimiento       | Descripción
| ---------------- | ----------------------------------------------------------- |
| `swap`           | Intercambia el primer y segundo elemento de un stack        |
| `push`           | Saca el primer nodo del stack y lo empuja en el primero     |
| `rotate`         | Rota el stack pasando el primero a la ultima posicion       |
| `reverse rotate` | Rota el stack pasando el ultimo a la primera posicion       |

# Logica de los movimientos

## swap
```
swap(stack)
	almacena el puntero al 3er nodo
	cambia el puntero del segundo y ahora apunta al 1º
	cambia el puntero del primero y ahora apunta al 3º
	cambia el puntero *top y ahora apunta al que era el segundo nodo
```

## push
```
push(stack origen, stack objetivo)
	almacena el next del top 
```
## rotate

## reverse rotate


