# Busy

**Robô de atendimento autônomo para o varejo brasileiro.**

O Busy é um assistente físico de loja, de baixo custo, que recebe o cliente, exibe mensagens em uma tela OLED e se move (rosto + pescoço mecânicos) para humanizar a experiência de compra. Feito para pequenos comércios que não têm orçamento para soluções de automação caras.

> Status: protótipo em desenvolvimento — firmware funcional, hardware em aquisição.

---

## Por que existe

Pequenos lojistas no interior (como Paulo Afonso - BA) não têm acesso a tecnologia de atendimento que grandes redes têm. O Busy nasce como uma alternativa **aberta e barata**: um robô que qualquer comerciante possa ter na loja, com peças de poucos reais e software livre.

## O que ele faz (visão do produto)

- Recebe o cliente com uma **expressão** na tela (sorrindo, neutro, animado)
- Faz **movimentos** físicos (acena, olha para cima/baixo) via servos pan/tilt
- Consulta um **cérebro** que decide, momento a momento, o que exibir
- Roda em um ESP32-S3 (microcontrolador de ~R$ 115)

---

## Stack

| Camada | Tecnologia |
|--------|-----------|
| Firmware | C++ (Arduino framework) |
| Build | PlatformIO |
| Display | Adafruit SSD1306 (OLED 1.3" I2C) |
| Movimento | ESP32Servo (MG90S x2, pan/tilt) |
| Conectividade | WiFi (HTTP polling) |
| Cérebro | Python + Flask (servidor local) |
| Formato de mensagem | JSON (`expressao`, `movimento`) |

## Arquitetura

```
[Busy / ESP32-S3]  --HTTP GET /proximo-->  [Cérebro Flask]  --(futuro)-->  [Hermes / IA]
   OLED + servos                                 decide ação
```

O ESP32 é propositalmente "burro": ele apenas exibe e move. A inteligência fica no cérebro, que hoje é um servidor local simples e, no futuro, pode ser uma IA conversando com o cliente.

---

## Como rodar (modo desenvolvedor)

### Pré-requisitos
- PlatformIO instalado no VS Code
- Python 3.10+ (para o cérebro)
- ESP32-S3-DevKitC-1

### 1. Cérebro (servidor local)
```bash
cd busy_firmware/brain
python3 -m venv venv
source venv/bin/activate
pip install flask
python server.py
```
O cérebro sobe em `http://0.0.0.0:8000` e responde `/proximo` com a próxima ação.

### 2. Firmware
- Abra a pasta `busy_firmware` no VS Code (extensão PlatformIO)
- Edite `src/config.h` com seu WiFi e o IP da máquina rodando o cérebro
- Conecte o ESP32-S3 via USB
- Botão **Upload**

### 3. Teste sem hardware (opcional)
O cérebro pode ser testado isoladamente:
```bash
curl http://localhost:8000/proximo
# retorna: {"expressao":"sorrindo","movimento":"acena_direita"}
```

---

## Pinagem (provisional)

| Componente | Pino |
|-----------|------|
| OLED SDA | 21 |
| OLED SCL | 22 |
| Servo PAN | 13 |
| Servo TILT | 14 |

> ⚠️ Pinos ainda sujeitos a ajuste conforme montagem final do protótipo.

---

## Roadmap

- [x] Firmware base (display + servo + wifi)
- [x] Cérebro Flask local
- [ ] Aquisição das peças (kit ~R$ 360)
- [ ] Integração com IA (Hermes como cérebro conversacional)
- [ ] Case físico (impressão 3D)
- [ ] Modo autônomo em loja real (piloto)

---

## Sobre

Projeto pessoal de **Matheus Rian** (Ciência da Computação, IFBA Paulo Afonso), com o objetivo de transformar em produto a ideia de um robô de atendimento acessível para o varejo brasileiro.

*Em construção — feedbacke e contribuições são bem-vindos.*
