# BIG O
> Es una forma de medir la eficiencia de un algoritmo en informática.

Indica cómo crece el tiempo de ejecución o el uso de memoria a medida que aumenta el tamaño de los datos de entrada.

Por ejemplo:

O(1) → tiempo constante. Siempre tarda lo mismo.

O(log n) → crecimiento logarítmico, como la búsqueda binaria.

O(n) → crecimiento lineal; recorre todos los elementos una vez.

O(n²) → crecimiento cuadrático; suele aparecer con dos bucles anidados.

O(2ⁿ) → crecimiento exponencial; se vuelve muy costoso rápidamente.

El orden de eficiencia, de mejor a peor, suele ser:

> O(1) < O(log n) < O(n) < O(n *log n) < O(n * Vn) < O(n²)

![grafico representando las complejidades](https://developero.io/_next/image?url=/static/images/posts/big-o/big-o-notation-examples-javascript/big-o-notation-graph.webp&w=1920&q=75)

## Notaciones comunes

# ALGORITMOS

## 0(n²) 
### Insertion Sort (LIS)
> Ordenar listas **insertando** elementos en su lugar

Empiezas en la segunda posicion de la lista y lo insertas en su posicion relativa al primero
Luego tomas la 3ª posicion
repites hasta el final

```C
[5, 2, 4, 6, 1, 3] // Tomamos el 2 (i)
↓
[2, 5, 4, 6, 1, 3] // Tomamos el 4 (i + 1)
↓
[2, 4, 5, 6, 1, 3] // Tomamos el 6 (i + 2)
↓
[2, 4, 5, 6, 1, 3] // Tomamos el 1
↓
[1, 2, 4, 5, 6, 3] // Tomamos el 3
↓
[1, 2, 3, 4, 5, 6]
```

```
para i desde 1 hasta n−1:
    clave = A[i]
    j = i − 1

    mientras j >= 0 y A[j] > clave:
        A[j+1] = A[j]
        j = j − 1

    A[j+1] = clave
```

#### Implementacion Push_Swap

### Selection Sort (SSS)
> Ordenar listas **seleccionando** el minimo en cada paso

Buscas el elemento mas pequeño de la parte no ordenada y lo inserta en su posicion definitiva

```C
[64, 25, 12, 22, 11] // Buscamos el 11 y lo ponemos 1º
↓
[11, 25, 12, 22, 64] // buscamos el 12 y lo ponemos 2º
↓
[11, 12, 25, 22, 64]
↓
[11, 12, 22, 25, 64]
↓
[11, 12, 22, 25, 64]
```

## O(nVn)
### Chunk Sort

## 0(n log n)
### Radix Sort
### Merge Sort
### Turk Algorithm



