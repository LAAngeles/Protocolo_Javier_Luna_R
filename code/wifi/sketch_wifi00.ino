// Conexión por DHCP
// Paso 1: configurar el SSID y password
// Paso 2: config ip, default gateway (ip router) y mask
// la configuración depende si se hace por DHCP o statica
// los dispositivos de red caseros trabajan con la DHCP
// --------------------------------------------------------
// Los recursos para modo estación estan en la clase WiFiSTAClass
// wl_status_t begin(char* ssid, char *passphrase = NULL, int32_t channel = 0, const uint8_t* bssid = NULL, bool connect = true);
// STA network info
// IPAddress localIP();
#include <WiFi.h>

const uint16_t port = 8000; // 2^16 = 65,536 puertos disponibles para el servidor

WiFiServer server(port);  // se crea un objeto WiFiServer que crea un servidor para escuchar conexiones entrantes del cliente

const char ssid[] = "ULTRON 7186";    // Nombre de la red WiFi 
const char passphrase[] = "x:L78467"; // Contraseña de la red WiFi

void setup() {
  Serial.begin(115200); // se inicia la comunicacion serial
  while(!Serial){delay(25);}
  set_up_WIFI();
  server.begin(); // comienza a escuchar conexiones entrantes del cliente
}

void loop() {
  // para escuchar las peticiones del cliente se crea un objeto de WiFiClient
  WiFiClient cliente = server.available(); // detecta al cliente que en este ejemplo es Node-Red
  if (cliente) {
    Serial.println("Se detecto un cliente en la conexión");
    while(cliente.connected()){
      if(cliente.available()){
        char c = cliente.read();
        Serial.println(c);
        if(c == 'a'){
          cliente.print("El servidor recibio un byte del cliente por TCP");
        }
      }
    }
  }
  //---------------------------------------
  if(WiFi.status() == WL_DISCONNECTED){
    Serial.println("Desconectado ");
    delay(5000);
  }
  //---------------------------------------
}

void set_up_WIFI(){

  Serial.print("Estableciendo conexión WiFi con ");
  Serial.print(ssid);

  WiFi.begin(ssid, passphrase);
  
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(50);
  }
  
  Serial.println("");
  Serial.println("Conexión exitosa con ESP32!!!");
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());
  Serial.print("Mask : ");
  Serial.println(WiFi.subnetMask());
  Serial.print("GatewayIP : ");
  Serial.println(WiFi.gatewayIP()); // tipo de red
}