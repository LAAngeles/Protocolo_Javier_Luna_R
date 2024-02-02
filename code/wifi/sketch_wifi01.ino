// --------------------------------------------------------
// Cofiguración estática en esp32-c6
// --------------------------------------------------------
#include <WiFi.h>

// Se crean tres objetos de la clase IPAddress
IPAddress local_ip(192,168,137,101);  //Se configura la IP estática, está se escribe en Node-Red
// Nota: Para el Gateway abre la terminal con cmd y escribe ipconfig, busca Adaptador de LAN inalámbrica conexión de área local, Dirección IPv4. 
IPAddress gateway(192,168,137,1);     // puerta de enlace 
IPAddress subnet(255,255,255,0);      //Máscara de subred

const uint16_t      port = 8000; // 2^16 = 65,536 puertos disponibles para el servidor
const char        ssid[] = "ULTRON 7186";    // Nombre de la red WiFi 
const char  passphrase[] = "x:L78467"; // Contraseña de la red WiFi

WiFiServer server(port);  // se crea un objeto de la clase WiFiServer que crea un servidor para escuchar conexiones entrantes del cliente

void setup() {

  Serial.begin(115200); // se inicia la comunicacion serial
  while(!Serial){delay(25);}
  // ---------------------------
  // bool config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1 = (uint32_t)0x00000000, IPAddress dns2 = (uint32_t)0x00000000);
  WiFi.config(local_ip,gateway,subnet);
  // ---------------------------
  set_up_WIFI();  // función para establecer la conexión WiFi
  server.begin(); // comienza a escuchar conexiones entrantes del cliente
  set_up_Cliente(); 
  //----------------------------
  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);
  //----------------------------
}

void loop() {
  
  // para escuchar las peticiones del cliente se crea un objeto de WiFiClient
  WiFiClient cliente = server.available(); // detecta al cliente que en este ejemplo es Node-Red
  if (cliente) {
    while(cliente.connected()){
      if(cliente.available()){
        char c = cliente.read();

        String stringZero = String(analogRead(0), HEX);          // using an int and a base (hexadecimal)
        String stringOne =  String(analogReadMilliVolts(0), DEC); // using an int and a base
        String stringTWO =  String(stringZero + "," + stringOne); // concatenating strings
        
        Serial.println(c);
        Serial.println(stringTWO);
        
        if(c == 'a'){
          cliente.print(stringTWO);
        }else {
          cliente.print("Conexión correcta con la ESP32 ");
        }
      }
    }
  }
  //---------------------------------------
  if(WiFi.status() == WL_DISCONNECTED){
    Serial.println("WiFi desconectado ");
    delay(5000);
  }
  //---------------------------------------
}
/////////////////////////////////////////////////////////////////////////
void set_up_WIFI(){

  Serial.print("Estableciendo conexión WiFi con ");
  Serial.print(ssid);

  WiFi.begin(ssid, passphrase);
  
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(50);
  }
  
  Serial.println("");
  Serial.println("Conexión exitosa WiFi!!!");
  Serial.print("Port: ");
  Serial.println(port);
  Serial.print("Server: ");
  Serial.println(WiFi.localIP());
  Serial.print("GatewayIP: ");
  Serial.println(WiFi.gatewayIP()); // tipo de red
  Serial.print("Subnet: ");
  Serial.println(WiFi.subnetMask());
}
/////////////////////////////////////////////////////////////////////////
void set_up_Cliente(){

  Serial.println("Configura y manda un byte para");
  Serial.println("establecer la conexión con Node-Red");
  while (!server.hasClient()) {
    Serial.print(".");
    delay(50);
  }

  Serial.println();
  Serial.println("Conexión exitosa con Node-Red!!!");
}
/////////////////////////////////////////////////////////////////////////
