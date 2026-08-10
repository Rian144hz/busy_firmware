// ============================================================
//  display.h  -  cabecalho do modulo de tela OLED
//  (voce mexe aqui so se quiser adicionar novas "caras")
// ============================================================
#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

// Inicia o display (chamar uma vez no setup)
void display_iniciar();

// Mostra uma "expressao" textual no centro da tela.
// Exemplo: display_mostrar("sorrindo")
void display_mostrar(const String& expressao);

// Limpa a tela
void display_limpar();

#endif
