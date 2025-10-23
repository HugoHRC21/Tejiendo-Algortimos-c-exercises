El mecanismo de acceso directo a los elementos de un arreglo n-dimensional se basa en el uso 
de una fórmula que calcula la dirección de un elemento específico utilizando sus índices en cada 
dimensión. Cada arreglo tiene una dirección base, que es la ubicación de memoria donde comienza 
el almacenamiento de los elementos. Para acceder a un elemento en un arreglo n-dimensional, se 
utiliza la fórmula: Dirección(i1, i2, ..., in) = D + (i1 * n2 * n3 * ... * nN + i2 * n3 * ... * nN + ... + in) * tamaño, 
donde D es la dirección base, i1, i2, ..., in son los índices de cada dimensión, n2, n3, ..., nN son el 
número de elementos en las dimensiones restantes, y tamaño es el tamaño en bytes de cada elemento. 
Este mecanismo permite acceder a cualquier elemento de manera eficiente, utilizando los índices para 
calcular directamente su dirección en la memoria, lo que asegura un acceso rápido