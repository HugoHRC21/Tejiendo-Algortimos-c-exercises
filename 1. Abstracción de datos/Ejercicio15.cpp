/*  Asuma que el fin de un sistema es la administración de la escolaridad de una carrera
universitaria. Bajo este fin se desea disponer de bases de datos de estudiantes, 
profesores, carreras, cursos, secciones, salones, horarios y demás aspectos propios de la
administración escolar de una universidad.
Plantee TAD generales, particulares y parametrizados, que modelicen las diversas 
abstracciones que manejaría el sistema. Dibuje los diagramas UML para todas las clases
diseñadas.  */

                 +--------------------+
                 |       Persona      |
                 +------------------- +
                 | - nombre           |
                 | - apellido         |
                 | - ID               |
                 +--------------------+
                 | + getNombre()      |
                 | + getApellido()    |
                 | + getID()          |
                 +--------------------+
                            ^
             _______________|_________________
            |                                 |
+-------------------------+    +------------------------+
|        Estudiante       |    |         Profesor       |
+-------------------------+    +------------------------+
| - matricula             |    | - departamento         |
| - cursos: List<Curso>   |    | - cursos: List<Curso>  |
+-------------------------+    +------------------------+
| + inscribirCurso()      |    | + asignarCurso()       |
| + getCursos()           |    | + getCursos()          |
+-------------------------+    +------------------------+

+-----------------+
|      Curso      |
+-----------------+
| - nombre        |
| - codigo        |
| - creditos      |
+-----------------+
| + getNombre()   |
| + getCodigo()   |
| + getCreditos() |
+-----------------+

+-----------------+
|     Seccion     |
+-----------------+
| - codigo        |
| - curso         |
| - profesor      | 
| - horario       |
+-----------------+
| + getHorario()  |
| + getCodigo()   |
| + getProfesor() |
| + getCurso()    |
+-----------------+

+----------------------+
|        Carrera       |
+----------------------+
| - nombre             |
| - codigo             |
| - cursos:List<Curso> |
+----------------------+
| + agregarCurso()     |
| + getCursos()        |
+----------------------+

+---------------------------+
|           Horario         |
+---------------------------+
| - secciones: List<Seccion>|
+---------------------------+
| + agregarSeccion()        |
| + getSecciones()          |
+---------------------------+