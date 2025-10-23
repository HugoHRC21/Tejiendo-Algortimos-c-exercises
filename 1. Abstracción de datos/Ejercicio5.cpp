
/*Revise fuentes de programas libres para dibujar como Xfig y DIA e indague la jerarquía
de clases con que ellos modelizan las figuras.
*/

Xfig y Dia son herramientas de software utilizadas para crear diagramas y gráficos, pero tienen características y enfoques diferentes.

Xfig:
Descripción: Xfig es un programa de diagramación que permite crear gráficos y diagramas en 2D. Es especialmente popular en sistemas Unix y Linux.
Características:
Interfaz gráfica que permite la creación de diagramas mediante la selección y manipulación de formas.
Soporta la exportación a varios formatos de archivo, como EPS, PDF y SVG.
Permite la creación de diagramas técnicos, como diagramas de flujo, gráficos de funciones y esquemas.

Modelo de Objetos:
Xfig utiliza una estructura de datos basada en diferentes tipos de objetos gráficos, como líneas, polígonos, arcos, textos, etc.
Cada figura se representa como una clase que hereda de una clase base, generalmente denominada Figure o similar.
Jerarquía de Clases:
Figure: Clase base que define las propiedades comunes (posición, tamaño, color).
Line, Circle, Polygon, Text: Clases derivadas que implementan propiedades y comportamientos específicos para cada tipo de figura.
Group: Puede ser una clase que agrupe varias figuras, permitiendo transformaciones conjuntas.
Interacción:
Las clases incluyen métodos para dibujar, mover, escalar y rotar figuras.




Dia:
Descripción: Dia es una herramienta de diagramación diseñada para ser fácil de usar, similar a Microsoft Visio, y es parte del proyecto GNOME.
Características:
Permite crear una amplia variedad de diagramas, como diagramas de flujo, diagramas UML, diagramas de red y más.
Tiene una interfaz intuitiva y soporta la creación de diagramas mediante la selección de plantillas y formas predefinidas.
También permite la exportación en varios formatos, como PNG, SVG y PDF.
Comparación
Uso: Xfig es más adecuado para usuarios que buscan un control detallado sobre el diseño y las propiedades de los gráficos, mientras que Dia es más accesible para usuarios que requieren una solución rápida y fácil para crear diagramas.
Interfaz: Xfig puede ser menos intuitivo para principiantes, mientras que Dia está diseñado para ser más amigable.

Modelo de Objetos:
Dia utiliza un modelo de objetos similar, donde cada figura es un objeto que tiene propiedades específicas y métodos asociados.
Usa un enfoque basado en diagramas, donde cada tipo de diagrama (UML, de flujo, etc.) tiene sus propias características.
Jerarquía de Clases:
DiaObject: Clase base que define las propiedades generales de todos los objetos gráficos.
Line, Ellipse, Rectangle, Text: Clases derivadas que implementan detalles específicos para cada figura.
Layer: Clase que agrupa objetos en diferentes capas, permitiendo gestionar la visibilidad y el orden de los elementos.
Interacción:
Las clases en Dia también permiten operaciones como mover, cambiar el tamaño y aplicar estilos a las figuras.
