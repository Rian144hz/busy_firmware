#!/usr/bin/env python3
# ============================================================
#  brain/server.py  -  O "cerebro" do Busy (servidor local)
#  Roda no seu PC. O ESP32 pergunta e ele responde o que fazer.
#  No futuro, aqui entra o Hermes (eu) decidindo a expressao/movimento.
#
#  Como usar:
#    1. instale:  pip install flask
#    2. rode:     python3 brain/server.py
#    3. o ESP32 ja aponta pra este IP na rede
# ============================================================
from flask import Flask, jsonify

app = Flask(__name__)

# Lista simples de "acoes" que o Busy pode fazer (simulacao inicial)
ACOES = [
    {"expressao": "sorrindo",     "movimento": "acena_direita"},
    {"expressao": "neutro",       "movimento": "parado"},
    {"expressao": "animado",      "movimento": "olha_cima"},
    {"expressao": "sorrindo",     "movimento": "acena_esquerda"},
]

indice = 0

@app.route("/proximo")
def proximo():
    global indice
    acao = ACOES[indice % len(ACOES)]
    indice += 1
    return jsonify(acao)

@app.route("/")
def home():
    return "Busy Brain online. Acesse /proximo"

if __name__ == "__main__":
    # 0.0.0.0 = escuta na rede local (o ESP32 alcanca pelo IP da maquina)
    app.run(host="0.0.0.0", port=8000, debug=True)
