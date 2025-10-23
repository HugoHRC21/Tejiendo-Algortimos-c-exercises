El mecanismo de acceso directo a los elementos de una matriz se basa en la organización
 de los datos en memoria y el uso de una fórmula matemática. Una matriz se compone de filas 
 y columnas, y cada elemento se almacena en una dirección de memoria contigua. Para acceder a 
 un elemento en la posición [i][j], se utiliza la dirección base de la matriz, que es la dirección 
 del primer elemento, y se aplica la fórmula: Dirección(i, j) = D + (k* n*i + i * n + j) * tamaño, 
 donde D es la dirección base, i es el índice de la fila, j es el índice de la columna, n es el 
 número total de columnas y tamaño es el tamaño en bytes de cada elemento. Por ejemplo, si tenemos 
 una matriz de 3 filas y 4 columnas, y queremos acceder al elemento en la posición [1][2], calculamos 
 su dirección utilizando la fórmula. Esto nos permite acceder directamente al elemento sin necesidad 
 de recorrer toda la matriz, logrando un acceso rápido y eficiente 