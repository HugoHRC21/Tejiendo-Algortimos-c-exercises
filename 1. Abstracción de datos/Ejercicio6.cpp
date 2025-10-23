
// /*Revise fuentes de programas libres para dibujar como Xfig y DIA e indague la jerarquía
// de clases con que ellos modelizan las figuras.
// */

// OBJETOS FUNDAMENTALES EN LA CABINA DE UN CARRO:

// VOLANTE
// Fin: Controlar la dirección del vehículo.
// Operaciones:
//     girar(dirección: String): Cambia la dirección del vehículo.
// Especificación:
//     Sintáctica: volante_girar("izquierda" | "derecha")
//     Semántica: Al girar, el vehículo va en la dirección especificada.
// PEDAL DE ACELERAR
// Fin: Aumentar la velocidad del vehículo.
// Operaciones:
//     presionar(intensidad: float): Aumenta la velocidad en función de la presión.
// Especificación:
//     Sintáctica: acelerador.presionar(0.75)
//     Semántica: Cuanto mayor sea la intensidad, mayor será la aceleración del vehículo.
// PEDAL DE FRENO
// Fin: Disminuir la velocidad o detener el vehículo.
// Operaciones:
// presionar(intensidad: float): Reduce la velocidad según la presión aplicada.
// Especificación:
//     Sintáctica: freno.presionar(0.0 - 1.0)
//     Semántica: Mayor presión resulta en una desaceleración más intensa.
// PALANCA DE CAMBIOS
// Fin: Cambiar entre las diferentes marchas del vehículo.
// Operaciones:
// cambiar(marcha: String): Cambia la marcha actual.
// Especificación:
//     Sintáctica: palanca.cambiar("P" | "R" | "N" | "D")
//     Semántica: Cambia la transmisión del vehículo a la marcha seleccionada.
// LUCES DE CRUCE
// Fin: Indicar a otros conductores la intención de girar o cambiar de carril.
// Operaciones:
// activar(dirección: String): Enciende el indicador en la dirección especificada.
// Especificación:
//     Sintáctica: indicador.activar("izquierda" | "derecha")
//     Semántica: El indicador se enciende, alertando a otros vehículos de la maniobra.
// ESPEJOS RETROVICEROS
// Fin: Proporcionar visibilidad hacia atrás y de los lados.
// Operaciones:
// ajustar(ángulo: float): Cambia la posición del espejo.
// Especificación:
//     Sintáctica: espejo.ajustar(ángulo)
//     Semántica: Ajusta el espejo para mejorar la visibilidad de los alrededores
//  SILLA DEL CHOFER
// Fin: Proporcionar comodidad y soporte al conductor.
// Operaciones:
// ajustar(posición: String): Cambia la posición del asiento.
// Especificación:
//     Sintáctica: asiento.ajustar("adelante").
//     Semántica: Modifica la posición del objeto asiento, moviéndolo hacia adelante para optimizar la postura del conductor.
