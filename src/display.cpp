// ============================================================
//  display.cpp  -  implementacao da tela OLED
//  Biblioteca: Adafruit_SSD1306  (tela 128x64, I2C)
// ============================================================
#include "display.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// Cria o objeto do display. 128x64 é o tamanho da tela 1.3"
Adafruit_SSD1306 tela(OLED_RESET, OLED_SDA, OLED_SCL);

void display_iniciar() {
  // begin() liga o display no endereco I2C definido em config.h
  if (!tela.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    // Se entrar aqui, o pino/endereco esta errado -> verifique config.h
    Serial.println("[DISPLAY] Falha ao iniciar OLED");
    return;
  }
  tela.clearDisplay();
  tela.setTextSize(2);             // tamanho da fonte
  tela.setTextColor(SSD1306_WHITE);
  tela.setCursor(0, 0);
  tela.println("BUSY");
  tela.display();                  // envia para a tela
}

void display_mostrar(const String& expressao) {
  tela.clearDisplay();
  tela.setTextSize(2);
  tela.setTextColor(SSD1306_WHITE);
  tela.setCursor(0, 0);
  tela.println("BUSY:");
  tela.setTextSize(1);             // menor para caber o texto
  tela.setCursor(0, 25);
  tela.println(expressao);
  tela.display();
}

void display_limpar() {
  tela.clearDisplay();
  tela.display();
}
