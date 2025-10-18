/*Critique el TAD hComplejo 5i. ¾Que tan completo es?, ¾es correcta su especicación
semántica?, ¾Qué problemas de dominio y resultados pueden ocurrir?*/

//Complejo 5
struct Complejo
{
Complejo(float r, float i);
Complejo(const Complejo & c);
float & obtenga_parte_real();
float & obtenga_parte_imag();
};

// Critica: 1. No posee metodos para usar dicho tipo de TAD
//          2. los metodos para obtener las partes reales e imaginarias permiten acceder a los atributos medinate el uso de & lo cual no debe permitirs.
//          3. No hay ningun tipo de Validacion para los argumentos del primer constructo
//          4. No se definen claramente los atributos lo que permite mdificarlos sin los metodos adecaudos
//          5. No hay metodos para mostrar el numero complejo por completo.
//          5. No hay metodos para mostrar el numero complejo por completo.




