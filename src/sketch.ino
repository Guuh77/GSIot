#include <WiFi.h>
#include "ThingSpeak.h"
#include <DHT.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

//ThingSpeak
unsigned long myChannelNumber = 1;
const char* myWriteAPIKey = "U2AC4SJQU8HQ3P0W";

//Configurações do Sensor
#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  
  Serial.print("Conectando ao WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConectado!");
}

void loop() {
  // 1. Coleta de Dados
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  // Verifica se a leitura falhou
  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Falha ao ler do sensor DHT!");
    return;
  }

  // Exibe no console
  Serial.print("Temp: "); Serial.print(temperatura);
  Serial.print("C | Umid: "); Serial.print(umidade); Serial.println("%");

  // 2. ThingSpeak
  ThingSpeak.setField(1, temperatura);
  ThingSpeak.setField(2, umidade);

  // 3. Envio dos dados
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  if(x == 200){
    Serial.println("Dados enviados com sucesso para o Dashboard.");
  }
  else{
    Serial.println("Erro no envio: " + String(x));
  }
  delay(20000);
}
