#include <Ethernet.h>
#include <SPI.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0xF3, 0xB1};
EthernetClient client;
IPAddress server (192,168,1,229);
IPAddress ip(192,168,1,75);
String data;

void setup() { 
	Serial.begin(9600);
  Serial.println("Program started.");
	Ethernet.begin(mac, ip); 
	delay(1000);
	data = "a";
}

void loop()
{
	data = "hello";
//Serial.println("");
  Serial.println("Before connecting.");
	if (client.connect(server,80))// REPLACE WITH YOUR SERVER ADDRESS
	{


    /*Serial.println("client connected OK");
    client.print("GET /work/arduino/add.php?Time=77&People=777\n");
    client.println("HTTP/1.1");
    client.println("Host: 192.168.1.229");
    client.println();
    client.println();
  
    Serial.println("Connected!");
		client.println("GET /work/arduino/add.php?Time=77&People=777 HTTP/1.1"); 
		client.println("Host: localhost");
    client.println("User-Agent: EtherShield/1.6");
    client.println("Accept: text/html"); 
    client.println("Connection: close");
		//client.println("Content-Type: application/x-www-form-urlencoded"); 
		//client.print("Content-Length: "); 
		//client.println(data.length()); 
		client.println(); 
		client.print(data); */

    // Print for debugging
    Serial.print("GET /work/arduino/add.php?Time=77&People=777");
    Serial.println(" HTTP/1.1");
    Serial.print("Host: ");
    Serial.println(server);
    Serial.println("Connection: close");
    
    client.print("GET /work/arduino/add.php?Time=77&People=777");
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
    client.println();
    client.stop();
  }

  else {
    Serial.println("Connection failed\n");
  }
  Serial.println("\n\n");

	delay(1000);
}



