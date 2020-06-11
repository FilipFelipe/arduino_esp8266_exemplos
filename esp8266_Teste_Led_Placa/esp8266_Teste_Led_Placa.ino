/*
https://github.com/FilipFelipe
Exemplo de um teste simples para verificação do LED na placa do ESP8266.

*/
void setup() {
// Define D4 como saida
pinMode(D4, OUTPUT);
Serial.begin(115200);
}
void loop() {
Serial.println("Desligado");  
digitalWrite(D4, HIGH); // Desliga o Led
delay(1000); // Aguarda 1 segundo
Serial.println("Ligado");  
digitalWrite(D4, LOW); // Liga o Led 
delay(1000); // Aguarda 1 segundo
}
