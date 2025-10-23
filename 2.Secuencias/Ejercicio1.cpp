/*Por qué la búsqueda binaria no debe utilizarse para elementos ordenados en un archivo
almacenado en memoria secundaria?*/

// La búsqueda binaria es un algoritmo eficiente para encontrar elementos en arreglos ordenados, pero no es 
// adecuada para elementos almacenados en archivos en memoria secundaria por varias razones:

// 1. Acceso Secuencial en Disco
// En memoria secundaria (como discos duros o SSDs), el acceso a datos no es tan rápido como en memoria RAM.
// La búsqueda binaria requiere acceder a múltiples ubicaciones de memoria, lo que puede resultar en un alto 
// número de accesos al disco, aumentando el tiempo de búsqueda.

// 2. Fragmentación y Carga de Datos
// Los archivos en disco pueden estar fragmentados, lo que significa que los bloques de datos no están almacenados de manera contigua.
// Esto puede hacer que los accesos aleatorios necesarios para la búsqueda binaria sean aún más lentos.

// 3. Costos de Entrada/Salida (I/O)
// Cada acceso a disco implica un costo de I/O significativo. La búsqueda binaria puede requerir 
// acceder a posiciones no contiguas, lo que incrementa el número de operaciones de I/O.
// Esto puede hacer que la búsqueda binaria sea ineficiente en comparación con métodos que requieren menos accesos.

// 4. Estrategias Alternativas
// Para archivos grandes, es preferible utilizar métodos como la búsqueda secuencial o estructuras de 
// datos como índices, que pueden minimizar el número de accesos al disco.
// Los índices permiten localizar rápidamente bloques de datos sin necesidad de acceder a cada elemento de forma individual.

// 5. Búsquedas en Archivos Ordenados
// En sistemas de bases de datos y sistemas de archivos, se suelen utilizar estructuras indexadas 
// (como B-trees) que son más adecuadas para búsquedas en archivos grandes, ya que están diseñadas
// para minimizar el número de accesos al disco.