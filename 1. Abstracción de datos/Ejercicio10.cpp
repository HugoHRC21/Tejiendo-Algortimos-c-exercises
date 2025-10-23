
/* Mencione tres o más aplicaciones en las que aparezca el problema fundamental de las
estructuras de datos. Para cada aplicación, explique la forma en que aparece y diserte
brevemente acerca de cómo se implantaría. */


// 1. Lista de Tareas 
// Forma en que aparece:
// En una aplicación de lista de tareas, se requiere organizar y gestionar tareas que el usuario debe completar. 
// El problema radica en cómo almacenar, agregar y eliminar tareas de manera eficiente.

// Implantación:
// Estructura de Datos Utilizada: Lista enlazada o arreglo.
// Implantación:
// Se puede utilizar un arreglo para almacenar las tareas, donde cada posición del arreglo representa una tarea.
// Se implementaría funciones para agregar (añadir al final del arreglo) y eliminar (remover de una posición específica) tareas.
// La interfaz permitiría al usuario ver la lista y marcar tareas como completadas.

// 2. Agenda de Contactos
// Forma en que aparece:
// Una agenda de contactos necesita almacenar información sobre personas, como nombres y números de teléfono. 
// El reto es cómo organizar y buscar contactos de manera eficiente.

// Implantación:
// Estructura de Datos Utilizada: Array de objetos.
// Implantación:
// Se puede usar un diccionario donde las claves son los nombres y los valores son los números de teléfono.
// Se implementarían funciones para agregar nuevos contactos, buscar un contacto por nombre y eliminar contactos.
// La interfaz permitiría al usuario ver todos los contactos y realizar búsquedas rápidas.

// 3. Contador de Palabras en un Texto
// Forma en que aparece:
// Al analizar un texto, se necesita contar cuántas veces aparece cada palabra. 
// El desafío es cómo almacenar y acceder a las palabras y sus contadores de manera eficiente.

// Implantación:
// Estructura de Datos Utilizada: Diccionario o mapa.
// Implantación:
// Se utilizaría un diccionario donde las claves son las palabras y los valores son sus respectivos contadores.
// Al procesar el texto, se iría agregando cada palabra al diccionario o aumentando su contador si ya existe.
// Se implementaría una función para mostrar el conteo de palabras al final del análisis.