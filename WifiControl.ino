/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>

const char* ssid = "ANONIMOS";
const char* password = "GU130603NA";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  // prepare GPIO2
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  digitalWrite(2, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(0, 0);
  digitalWrite(12, 0);
  digitalWrite(14, 0);
  
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("porta 1 conetada");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req1 = client.readStringUntil('\r');
  Serial.println(req1);
  client.flush();

  // Standby  
  if (req1.indexOf("/gpio5/1") != -1)
  {
  digitalWrite(5, HIGH);
  delay(200);
  digitalWrite(5,LOW);
  }
  // Fim Standby

  //Source
  else if (req1.indexOf("/gpio4/1") != -1)
  {
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4,LOW);;
  }  
  // Fim Source

  //Normal
  else if (req1.indexOf("/gpio0/1") != -1)
  {
  digitalWrite(0, HIGH);
  delay(200);
  digitalWrite(0,LOW);
  }
  //Fim Normal

  
  //Pro-Logic
  else if (req1.indexOf("/gpio2/1") != -1)
  {
  digitalWrite(2, HIGH);
  delay(200);
  digitalWrite(2,LOW);
  }
  //Fim Pro-Logic

  //Volume +
  else if (req1.indexOf("/gpio14/1") != -1)
  {
  digitalWrite(14, HIGH);
  delay(200);
  digitalWrite(14,LOW);
  }
  //Fim Volume +

  //Volume -
  else if (req1.indexOf("/gpio12/1") != -1)
  {
  digitalWrite(12, HIGH);
  delay(200);
  digitalWrite(12,LOW);
  }
  //Fim volume -
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }
  
  client.flush();
  delay(1);
  Serial.println("porta 1 desconetada");
}
