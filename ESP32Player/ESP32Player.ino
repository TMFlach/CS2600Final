#include <WiFi.h>
#include <PubSubClient.h>
//wifi variables
const char *ssid_Router     = "ATTHvsZV22"; //Enter the router name
const char *password_Router = "connie8891"; //Enter the router password
//mqtt variables
const char *mqtt_serv = "broker.emqx.io"; //mqtt server IP.
const char *topic = "esp32/TTTGame";
const int mqtt_port = 1883;
const char *username = "ConsolePlayer";
const char *mqtt_pw = "PlayAllDay";

WiFiClient wifiClient;
PubSubClient client(wifiClient);

#define LED_BUILTIN 2

void setup(){
  Serial.begin(115200);
  delay(200);
  Serial.println("Setup start");
  pinMode(LED_BUILTIN, OUTPUT);
  setup_wifi();
  client.setServer(mqtt_serv, mqtt_port);
  client.setCallback(callback);
  while(!client.connected()) {
    String id = "Player-";
    id += String(WiFi.macAddress());
    Serial.printf("The client %s connected to public broker\n", id.c_str());
    if(client.connect(id.c_str(), username, mqtt_pw)) {
      Serial.println("Connection successful.");
    } else {
      Serial.print("Connection failed");
      Serial.print(client.state());
      delay(2000);
    }

    //test publish and subscribe
    client.publish(topic, "Hello World, I'm a ESP32");
    client.subscribe(topic);
  }
  Serial.println("Setup End");
}

void setup_wifi() {
  delay(10);
  WiFi.begin(ssid_Router, password_Router);
  Serial.println(String("Connecting to ")+ssid_Router);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  //reconnect MQTT
  while(!client.connected()) {
    Serial.print("Attempting MQTT connect. ");
    String id = "Player-";
    id += String(WiFi.macAddress());
    if(client.connect(topic, username, mqtt_pw)) {
      Serial.println("Connected");
      client.subscribe(topic);
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println("Trying again in a sec or two.");
      delay(2000);
    }
  }
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrive from topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String read;
  for(int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    read += (char)message[i];
  }
  Serial.print(read);
  if(read.equals("X")) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.println();
}
 
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

}
