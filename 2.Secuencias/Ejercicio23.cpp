// (a) ¿Puede implantarse DynMatrix<T> a partir del TAD DynArray<T>?
// Sí, definitivamente puede implementarse.

// Una matriz dinámica es conceptualmente un arreglo de arreglos, y eso se adapta muy bien a usar un DynArray<DynArray<T>> como estructura base.

// Ejemplo básico:
// cpp
// Copy
// Edit
// DynArray<DynArray<T>> matrix;
// Esto te da una estructura donde:

// matrix[i] accede a la i-ésima fila.

// matrix[i][j] accede al elemento en la fila i, columna j (porque matrix[i] es un DynArray<T>).

// Ventajas:
// Reutilizás toda la lógica de memoria dinámica y crecimiento perezoso (lazy allocation) del DynArray<T>.

// Evitás reescribir el manejo de bloques, segmentos y directorios.

// (b) ¿Puede usarse una implantación independiente más eficiente?
// Sí, en casos muy específicos podría ser más eficiente.

// ¿Cuándo?
// Cuando:

// Se requiere acceso realmente continuo a la memoria (mejor para cache).

// Las dimensiones son grandes y estables, y no se necesita crecimiento desigual.

// Se busca evitar el overhead de la doble indirecta (matrix[i][j] implica dos accesos indirectos).

// Alternativa:
// Implementar la matriz como un solo DynArray<T> lineal, y mapear los índices con:

// cpp
// Copy
// Edit
// index = i * num_cols + j;
// Esto da una representación row-major (estilo C). Puede dar mejor rendimiento para recorrido secuencial.