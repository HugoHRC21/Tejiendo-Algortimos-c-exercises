// Definiciones
// M: Memoria total disponible (en bytes).
// S: Memoria máxima permitida por una llamada a new (en bytes).
// T: Tamaño de cada elemento del arreglo dinámico (en bytes).




// CONSIDERACIONES
// Tamaño del Directorio:
// El directorio puede incluir información sobre el tamaño del arreglo, el tamaño 
// de cada elemento, etc. Si usamos un tamaño reducido, más memoria estará disponible para el arreglo.

// Tamaño de Segmento:
// Es el tamaño de bloques de memoria asignados. Debe ser suficientemente grande
// para permitir la asignación de múltiples elementos, pero no tan grande que cause desperdicio de memoria.

// Tamaño de Bloque:
// Es el tamaño de cada bloque de memoria asignado para un arreglo. Debe ser 
// elegido de manera que maximice el uso eficiente de la memoria.




// CALCULOS:
// Para maximizar la dimensión del DynArray<T>, considera la siguiente fórmula:

// Número máximo de elementos:
//         N = (M - D) / T;
// donde D es el tamano del directorio

// Condiciones de asignación:
// Asegúrate de que la memoria asignada no exceda 
//         N ⋅ T <= S;




// ESTRATEGIA
// Minimizar el Tamaño del Directorio (D):     
// Si se puede, considera un directorio de tamaño constante (por ejemplo, 16 bytes) que almacene solo la información esencial.

// Elegir un Tamaño de Bloque (B):
// Un tamaño de bloque que sea múltiplo de 𝑇 puede ser eficiente. Por ejemplo, si 𝑇 = 4, considera 𝐵=8 o 𝐵=16 

// Calcular la Capacidad:
// Asegúrate de que la suma del directorio y el bloque no exceda M.




Ejemplo Práctico

M=1024 bytes
S=256 bytes
T=4 bytes (cada elemento del arreglo)

Tamaño del Directorio (D): 16 bytes.
Tamaño Máximo de Elementos:
N = (1024-16) / 4 
N = 253
Verificar el Límite de Asignación:

N ⋅ T = 253 ⋅ 4 = 1012 bytes (esto es menor que S, por lo que es válido).




