// ============================================================
//  servos.cpp  -  implementacao dos 2 servos MG90S (pan/tilt)
//  Biblioteca: ESP32Servo
//  MG90S gira de 0 a 180 graus. 90 = centro.
// ============================================================
#include "servos.h"
#include <ESP32Servo.h>

Servo servoPan;
Servo servoTilt;

void servos_iniciar() {
  // Avisa a biblioteca em qual pino cada servo esta
  servoPan.setPeriodHertz(50);       // 50Hz = padrao de servo
  servoTilt.setPeriodHertz(50);
  servoPan.attach(SERVO_PAN_PIN, 500, 2400);   // 500-2400us = faixa de pulso
  servoTilt.attach(SERVO_TILT_PIN, 500, 2400);
  servo_centralizar();
}

void servo_centralizar() {
  servoPan.write(90);    // centro
  servoTilt.write(90);   // centro
}

void servo_mover(const String& mov) {
  // Cada comando move um pouco e volta pro centro (movimento "vivo")
  if (mov == "acena_direita") {
    servoPan.write(150); delay(300); servo_centralizar();
  } else if (mov == "acena_esquerda") {
    servoPan.write(30);  delay(300); servo_centralizar();
  } else if (mov == "olha_cima") {
    servoTilt.write(150); delay(300); servo_centralizar();
  } else if (mov == "olha_baixo") {
    servoTilt.write(30);  delay(300); servo_centralizar();
  } else {
    // comando desconhecido -> so centraliza
    servo_centralizar();
  }
}
