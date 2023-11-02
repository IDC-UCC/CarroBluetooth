// Pines de control para el puente H L293B
int motor1EnablePin = 9; // Pin de habilitación del motor 1
int motor1Input1 = 8;    // Conexión de entrada 1 del motor 1
int motor1Input2 = 7;    // Conexión de entrada 2 del motor 1

int motor2EnablePin = 10; // Pin de habilitación del motor 2
int motor2Input1 = 12;    // Conexión de entrada 1 del motor 2
int motor2Input2 = 13;    // Conexión de entrada 2 del motor 2

int velocidad = 255;  // Velocidad máxima (0 a 255)

void setup() {
  // Configura los pines de control como salidas
  pinMode(motor1EnablePin, OUTPUT);
  pinMode(motor1Input1, OUTPUT);
  pinMode(motor1Input2, OUTPUT);
  pinMode(motor2EnablePin, OUTPUT);
  pinMode(motor2Input1, OUTPUT);
  pinMode(motor2Input2, OUTPUT);

  // Inicializa el Monitor Serial
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    // Control de dirección y velocidad de los motores
    if (command == 'F') {
      // Avanzar
      digitalWrite(motor1Input1, HIGH);
      digitalWrite(motor1Input2, LOW);
      digitalWrite(motor2Input1, HIGH);
      digitalWrite(motor2Input2, LOW);
      analogWrite(motor1EnablePin, velocidad);
      analogWrite(motor2EnablePin, velocidad);
    } else if (command == 'B') {
      // Retroceder
      digitalWrite(motor1Input1, LOW);
      digitalWrite(motor1Input2, HIGH);
      digitalWrite(motor2Input1, LOW);
      digitalWrite(motor2Input2, HIGH);
      analogWrite(motor1EnablePin, velocidad);
      analogWrite(motor2EnablePin, velocidad);
    } else if (command == 'L') {
      // Giro a la izquierda
      digitalWrite(motor1Input1, LOW);
      digitalWrite(motor1Input2, HIGH);
      digitalWrite(motor2Input1, HIGH);
      digitalWrite(motor2Input2, LOW);
      analogWrite(motor1EnablePin, velocidad);
      analogWrite(motor2EnablePin, velocidad);
    } else if (command == 'R') {
      // Giro a la derecha
      digitalWrite(motor1Input1, HIGH);
      digitalWrite(motor1Input2, LOW);
      digitalWrite(motor2Input1, LOW);
      digitalWrite(motor2Input2, HIGH);
      analogWrite(motor1EnablePin, velocidad);
      analogWrite(motor2EnablePin, velocidad);
    } else {
      // Detener motores
      analogWrite(motor1EnablePin, 0);
      analogWrite(motor2EnablePin, 0);
    }
  }
}
