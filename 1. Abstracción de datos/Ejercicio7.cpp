
// /*Diseñe inductivamente una jerarquía de clases que represente vehículos automotores.
// Dibuje los diagramas UML.
// */
//                     +---------------------+
//                     |      Vehículo       |  <-- Clase base
//                     +---------------------+
//                     | + marca             |
//                     | + modelo            |
//                     | + año               |
//                     | + color             |
//                     +---------------------+
//                     | + iniciar()         |
//                     | + detener()         |
//                     +---------------------+
//                                 ^
//          _______________________|__________________________
// +-------------------+  +-------------------+  +-------=-------------+
// |       Carro       |  |       Camion      |  |         Moto        |
// +-------------------+  +-------------------+  +-------=-------------+
// | + numPuertas      |  | + capacidadCarga  |  | + tipoManillar      |
// | + tipoCombustible |  +-------------------+  +---------------------+
// +-------------------+  | + cargar()        |  | + acelerar()        |
// | + acelerar()      |  | + descargar()     |  | + frenar()          |
// | + frenar()        |  | + retroceder      |  +---------------------+
// | + retroceder      |  +-------------------+
// +-------------------+