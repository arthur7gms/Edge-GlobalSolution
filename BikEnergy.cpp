#include <Servo.h>

int ledR = 13;      // LED Vermelho (Bike bloqueada)
int ledG = 12;      // LED Verde (Bike liberada)
int trigPin = 6;    // Pino Trig do sensor
int echoPin = 10;   // Pino Echo do sensor

bool bikeLiberada = false; // Estado da bike: false = bloqueada, true = liberada
Servo myServo;            // Objeto do servo motor

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(9);       // Conecta o servo no pino 9
  myServo.write(0);        // Inicia o servo em 0 graus (bloqueado)

  Serial.begin(9600);

  // Estado inicial
  digitalWrite(ledR, HIGH); // LED vermelho ligado
  digitalWrite(ledG, LOW);  // LED verde desligado
  Serial.println("Bike Bloqueada");
  Serial.println("Aproxime a mão do sensor para Desbloquear");
}

void loop() {
  // Envia pulso no Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calcula a distância
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // Conversão para cm

  // Verifica as condições para liberar ou bloquear a bike
  if (distance >= 5 && distance <= 50 && !bikeLiberada) {
    // Libera a bike
    bikeLiberada = true;
    digitalWrite(ledR, LOW);  // Apaga o LED vermelho
    digitalWrite(ledG, HIGH); // Acende o LED verde
    myServo.write(90);       // Move o servo para 180 graus (aberto)
    Serial.println("Bike Liberada");
  } else if (distance > 50 && bikeLiberada) {
    // Bloqueia a bike
    bikeLiberada = false;
    digitalWrite(ledR, HIGH); // Acende o LED vermelho
    digitalWrite(ledG, LOW);  // Apaga o LED verde
    myServo.write(0);         // Move o servo para 0 graus (fechado)
    Serial.println("Bike Bloqueada Novamente");
    Serial.println("Aproxime a mão do sensor para Desbloquear");
  }
}