// ============================================================
//  main.cpp  -  O CORACAO do Busy
//  setup() roda 1x; loop() repete pra sempre.
// ============================================================
#include <Arduino.h>
#include "config.h"
#include "display.h"
#include "servos.h"
#include "comms.h"

void setup() {
  Serial.begin(115200);
  Serial.println("=== BUSY FIRMWARE INICIANDO ===");

  display_iniciar();   // liga a telinha
  servos_iniciar();   // centraliza os servos
  wifi_conectar();    // entra no WiFi
}

void loop() {
  String expressao = "neutro";
  String movimento = "parado";

  // Pergunta ao cerebro o que fazer agora
  if (cerebro_consultar(expressao, movimento)) {
    Serial.println("Expressao: " + expressao + " | Movimento: " + movimento);
    display_mostrar(expressao);   // mostra a "cara"
    servo_mover(movimento);       // faz o movimento
  } else {
    // Se o cerebro nao respondeu, fica neutro esperando
    display_mostrar("aguardando");
  }

  delay(INTERVALO_MS);  // espera o tempo definido em config.h
}
