// ============================================================
//  comms.cpp  -  WiFi + falar com o "cerebro" (servidor Python)
//  Faz um GET e recebe um JSON: {"expressao":"sorrindo","movimento":"acena_direita"}
// ============================================================
#include "comms.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

void wifi_conectar() {
  Serial.print("[WIFI] Conectando a ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  // Espera ate conectar (max 10s)
  int tentativas = 0;
  while (WiFi.status() != WL_CONNECTED && tentativas < 20) {
    delay(500);
    Serial.print(".");
    tentativas++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n[WIFI] Conectado!");
  } else {
    Serial.println("\n[WIFI] Falhou - verifique SSID/senha em config.h");
  }
}

// Faz a pergunta ao cerebro e preenche as variaveis de saida.
// Retorna true se deu tudo certo.
bool cerebro_consultar(String& expressao, String& movimento) {
  if (WiFi.status() != WL_CONNECTED) return false;

  HTTPClient http;
  String url = String("http://") + BRAIN_IP + ":" + BRAIN_PORT + BRAIN_ENDPOINT;
  http.begin(url);
  int codigo = http.GET();

  if (codigo != 200) {
    http.end();
    return false;
  }

  String resposta = http.getString();
  http.end();

  // Faz o parse do JSON recebido
  JsonDocument doc;
  DeserializationError erro = deserializeJson(doc, resposta);
  if (erro) return false;

  expressao = doc["expressao"] | "neutro";
  movimento = doc["movimento"] | "parado";
  return true;
}
