/*
 https://github.com/FilipFelipe

 Exemplo de envio de um JSON via HTTP no ESP8266

 
*/
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
 
void setup() {
  Serial.begin(115200);                                                                       //Velocidade da Serial                          
  WiFi.begin("REDE", "SENHA");                                                                //Rede Wifi (Nome da rede e Senha) 
  while (WiFi.status() != WL_CONNECTED) {  
    delay(500);
    Serial.println("Aguardando a conexão do Wifi");
  } 
}

void loop() {
 if(WiFi.status()== WL_CONNECTED){                                                            //Verifica se o wifi está conectado
   HTTPClient http;                                                                           //Classe do HTTPClient
   http.begin("URL");                                                                         //URL para realizar o POST
   //http.addHeader("Content-Type", "text/plain");                                            //Para fazer envio em modo texto
   http.addHeader("Content-Type", "application/json");                                        //Para fazer envio do JSON
   int httpCode = http.POST("{\"valor1\":-10, \"valor2\":200,\"valor3\":\"1234\"}");          //Corpo do JSON
   String payload = http.getString();
   Serial.print("Código de Resposta: "); 
   Serial.println(httpCode); 
   Serial.println("Corpo da resposta: "); 
   Serial.println(payload);   
   http.end(); 
 }else{ 
    Serial.println("Erro na Conexão");   
 }
  delay(50000);
}
