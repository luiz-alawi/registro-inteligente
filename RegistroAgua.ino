#define BLYNK_TEMPLATE_ID "TMPL2X8DLVHzk"
#define BLYNK_TEMPLATE_NAME "Registro Agua"
#define BLYNK_AUTH_TOKEN "J1VkFOpyee6cVodEyZC5SXrQpSoC-NFm"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char ssid[] = "AMF-CORP";
char pass[] = "@MF$4515";

Servo servo;

#define SERVO_PIN D5

int ANGULO_ABERTO = 180;
int ANGULO_FECHADO = 0;

// Botão Push Abrir - V0
BLYNK_WRITE(V0) {
  if (param.asInt() == 1) {
    servo.write(ANGULO_ABERTO);
  }
}

// Botão Push Fechar - V1
BLYNK_WRITE(V1) {
  if (param.asInt() == 1) {
    servo.write(ANGULO_FECHADO);
  }
}

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(ANGULO_FECHADO);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}