¿Qué es random_select()?
Es un algoritmo para encontrar el i-ésimo menor elemento en un conjunto:
1. Elige un pivote al azar.
2. Separa los elementos en menores, iguales y mayores.
3. Según dónde cae el i-ésimo, seguimos solo en una parte (no en ambas como en Quicksort).

🚀 Caso esperado (promedio)
1. Cada vez que elegimos pivote, en promedio divide la lista en partes “razonables”.
2. Como solo seguimos con una de las partes, el tamaño baja rápido.
3. Costo total ≈ lineal en n → O(n).

O sea, si tienes 1 millón de elementos, el algoritmo se comporta como recorrerlos unas pocas veces, no mucho más.

⚠️ Caso peor
Puede pasar que el pivote siempre salga mal (por ejemplo, siempre el más pequeño o el más grande).
En ese caso solo quitamos 1 elemento por vez.
El costo se convierte en O(n²).

👉 Es raro que pase (porque el pivote se elige al azar), pero teóricamente es posible.

✅ Resumen sencillo
Esperado: O(n) (rápido, lineal).
Peor caso: O(n²) (muy lento, pero poco probable).
Si usamos trucos como elegir el pivote con una muestra y quedarnos con su mediana, reducimos el riesgo de malos pivotes (mejora práctica, pero la cota sigue siendo la misma).