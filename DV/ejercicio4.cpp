/*
Sea T(n) la función que describe el tiempo de ejecución de un algoritmo "divide y vencerás". Si T(n) es de la forma T(n)=aT(n/b)+n^k con a>=1, b>1, analice el tiempo de ejecución del algoritmo dependiendo de los valores de a y b.

El tiempo de ejecución de un algoritmo "divide y vencerás" puede ser analizado usando el Teorema Maestro, que proporciona una solución cerrada para recurrencias de la forma T(n) = aT(n/b) + f(n), donde a >= 1 y b > 1.

En tu caso, f(n) = n^k. Según el Teorema Maestro, hay tres casos que pueden ocurrir dependiendo de los valores de a, b y k:

1. Si a > b^k, entonces T(n) = Θ(n^log_b(a)).
2. Si a = b^k, entonces T(n) = Θ(n^k * log(n)).
3. Si a < b^k, entonces T(n) = Θ(n^k).

Por lo tanto, el tiempo de ejecución del algoritmo depende de los valores de a, b y k. Si a es mayor que b^k, entonces el tiempo de ejecución está dominado por las llamadas recursivas. Si a es igual a b^k, entonces el tiempo de ejecución es una combinación de las llamadas recursivas y el trabajo realizado en cada nivel de recursión. Si a es menor que b^k, entonces el tiempo de ejecución está dominado por el trabajo realizado en el nivel más alto de recursión.

Por favor, ten en cuenta que este es un análisis asintótico, lo que significa que describe el comportamiento del tiempo de ejecución a medida que n se acerca al infinito. Para valores pequeños de n, el tiempo de ejecución real puede variar.
*/