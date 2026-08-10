// ============================================================
//  comms.h  -  cabecalho de comunicacao (WiFi + cerebro)
// ============================================================
#ifndef COMMS_H
#define COMMS_H

#include <Arduino.h>

void wifi_conectar();
bool cerebro_consultar(String& expressao, String& movimento);

#endif
