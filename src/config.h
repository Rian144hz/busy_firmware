// ============================================================
//  config.h  -  AQUI VOCE MUDA OS PINOS E A REDE
//  (e nada mais, o resto do codigo usa essas variaveis)
// ============================================================

#ifndef CONFIG_H
#define CONFIG_H

// --- WiFi da loja (mude pros dados da sua rede) ---
#define WIFI_SSID     "SUA_REDE_WIFI"
#define WIFI_PASSWORD "SUA_SENHA"

// --- Onde roda o "cerebro" (o servidor Python no seu PC) ---
// 192.168.x.x  ->  descubra com 'ip a' no PC ou 'ipconfig' no Windows
#define BRAIN_IP      "192.168.1.50"
#define BRAIN_PORT    8000
#define BRAIN_ENDPOINT "/proximo"

// --- Pinos do OLED (tela 1.3" I2C) ---
// SDA = dados, SCL = clock. Verifique no seu modulo se tem resistor de pull-up.
#define OLED_SDA 21
#define OLED_SCL 22
#define OLED_ADDR 0x3C   // endereco I2C comum (se nao funcionar, tente 0x3D)
#define OLED_RESET -1    // -1 = sem pino de reset dedicado

// --- Pinos dos servos (pan = esquerda/direita, tilt = cima/baixo) ---
#define SERVO_PAN_PIN  13
#define SERVO_TILT_PIN 14

// --- Tempo entre consultas ao cerebro (em milissegundos) ---
#define INTERVALO_MS 4000   // pergunta a cada 4s o que fazer

#endif
