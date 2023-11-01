// Pins de control para los motores y configuración inicial
int motor2Pin1 = 7;
int motor2Pin2 = 8;
int motor2SpeedPin = 6;

int motor3Pin1 = 12;
int motor3Pin2 = 13;
int motor3SpeedPin = 11;

unsigned long tiempoInicio = 0;
unsigned long tiempoDuracion = 1000; // Duración en milisegundos

void setup() {
  // Configura los pines de control como salidas
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);

  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(motor3SpeedPin, OUTPUT);

  // Inicializa el Monitor Serial
  Serial.begin(9600);
}

// Función para avanzar durante un tiempo específico
void avanzar() {
  tiempoInicio = millis();
  while (millis() - tiempoInicio < tiempoDuracion) {
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motor2SpeedPin, 255);

    digitalWrite(motor3Pin1, HIGH);
    digitalWrite(motor3Pin2, LOW);
    analogWrite(motor3SpeedPin, 255);

  }

  detenerMotores();
  return;
}

void retroceder() {
  tiempoInicio = millis();
  while (millis() - tiempoInicio < tiempoDuracion) {
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(motor2SpeedPin, 50);

    digitalWrite(motor3Pin1, LOW);
    digitalWrite(motor3Pin2, HIGH);
    analogWrite(motor3SpeedPin, 255);
  }

  detenerMotores();
  return;
}
void derecha() {
  tiempoInicio = millis();
  while (millis() - tiempoInicio < tiempoDuracion) {
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motor2SpeedPin, 50);

    digitalWrite(motor3Pin1, HIGH);
    digitalWrite(motor3Pin2, LOW);
    analogWrite(motor3SpeedPin, 255);
  }

  detenerMotores();
  return;
}
void izquierda() {
  tiempoInicio = millis();
  while (millis() - tiempoInicio < tiempoDuracion) {
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(motor2SpeedPin, 255);

    digitalWrite(motor3Pin1, LOW);
    digitalWrite(motor3Pin2, LOW);
    analogWrite(motor3SpeedPin, 50);
  }

  detenerMotores();
  return;
}
// Función para detener los motores
void detenerMotores() {
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(motor2SpeedPin, 0);

  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);
  analogWrite(motor3SpeedPin, 0);

  return;
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 'F':
        Serial.println("FRENTE");
        avanzar();
        break;
      case 'B':
        Serial.println("REVERSA");
        retroceder();
        break;
      case 'L':
        Serial.println("DERECHA");
        derecha();
        break;
      case 'R':
        Serial.println("IZQUIERDA");
        izquierda();
        break;
      default:
        // Cualquier otro comando no reconocido
        break;
    }
  }
}
