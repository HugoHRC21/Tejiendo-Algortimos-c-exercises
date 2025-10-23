/*  Reconsidere el ejercicio anterior para ciclos escolares de secundaria y primaria.  */


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
|      materia    |
+-----------------+
| - nombre        |
| - codigo        |
| - nivel         |
| - creditos      |
+-----------------+
| + getNombre()   |
| + getCodigo()   |
| + getNivel()    |
| + getCreditos() |
+-----------------+

+-----------------+
|      Seccion    |
+-----------------+
| - codigo        |
| - materia       |
| - profesor      |
| - horario       |
+-----------------+
| + getHorario()  |
| + getCodigo()   |
| + getProfesor() |
| + getMateria()  |
+-----------------+


+-------------------------+
|          Grado          |
+-------------------------+
| - nivel                 |
| - cursos: List<materia> |
+-------------------------+
| + agregarMateria()      |
| + getMateria()          |
+-------------------------+

+----------------------------+
|           Horario          |
+----------------------------+
| - secciones: List<Seccion> |
+----------------------------+
| + agregarSeccion()         |
| + getSecciones()           |
+----------------------------+