// ============================================================
//  servos.h  -  cabecalho do modulo de movimento (pan/tilt)
// ============================================================
#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>

void servos_iniciar();
void servo_centralizar();              // volta ao meio
void servo_mover(const String& mov);  // recebe "acena_direita" etc

#endif
