#include <WiFi.h>
#include <WebServer.h>

// Wokwi Virtual WiFi Credentials
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Create WebServer object on port 80
WebServer server(80);

// Define GPIO Pins for Devices
const int device1 = 26; // Light 1
const int device2 = 27; // Light 2
const int device3 = 14; // Fan 1
const int device4 = 12; // Fan 2

// Status variables
bool status1 = false;
bool status2 = false;
bool status3 = false;
bool status4 = false;

// HTML Page Code (Stored in Program Memory)
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Home Automation Prototype</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial; text-align: center; margin: 0px auto; padding-top: 30px; background-color: #f4f4f4;}
    h1 { color: #333; }
    .button { display: inline-block; padding: 15px 25px; font-size: 24px; cursor: pointer; text-align: center; text-decoration: none; outline: none; color: #fff; background-color: #4CAF50; border: none; border-radius: 15px; margin: 5px;}
    .button:hover {background-color: #3e8e41}
    .button:active {background-color: #3e8e41; transform: translateY(4px);}
    .off {background-color: #e7e7e7; color: black;}
  </style>
</head>
<body>
  <h1>Smart Home Dashboard</h1>
  
  <h3>Living Room Light (Red)</h3>
  <a href="/toggle1"><button class="button %STATE1%">%TEXT1%</button></a>
  
  <h3>Kitchen Light (Green)</h3>
  <a href="/toggle2"><button class="button %STATE2%">%TEXT2%</button></a>
  
  <h3>Ceiling Fan (Blue)</h3>
  <a href="/toggle3"><button class="button %STATE3%">%TEXT3%</button></a>
  
  <h3>Exhaust Fan (Yellow)</h3>
  <a href="/toggle4"><button class="button %STATE4%">%TEXT4%</button></a>

</body>
</html>
)rawliteral";

// Function to generate the updated HTML page
String getPage() {
  String page = index_html;
  page.replace("%STATE1%", status1 ? "" : "off");
  page.replace("%TEXT1%", status1 ? "ON" : "OFF");
  page.replace("%STATE2%", status2 ? "" : "off");
  page.replace("%TEXT2%", status2 ? "ON" : "OFF");
  page.replace("%STATE3%", status3 ? "" : "off");
  page.replace("%TEXT3%", status3 ? "ON" : "OFF");
  page.replace("%STATE4%", status4 ? "" : "off");
  page.replace("%TEXT4%", status4 ? "ON" : "OFF");
  return page;
}

// Route Handlers
void handleRoot() {
  server.send(200, "text/html", getPage());
}

void handleToggle1() { status1 = !status1; digitalWrite(device1, status1); server.sendHeader("Location", "/"); server.send(303); }
void handleToggle2() { status2 = !status2; digitalWrite(device2, status2); server.sendHeader("Location", "/"); server.send(303); }
void handleToggle3() { status3 = !status3; digitalWrite(device3, status3); server.sendHeader("Location", "/"); server.send(303); }
void handleToggle4() { status4 = !status4; digitalWrite(device4, status4); server.sendHeader("Location", "/"); server.send(303); }

void setup() {
  Serial.begin(115200);
  
  // Initialize Pins
  pinMode(device1, OUTPUT);
  pinMode(device2, OUTPUT);
  pinMode(device3, OUTPUT);
  pinMode(device4, OUTPUT);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Setup Web Server Routes
  server.on("/", handleRoot);
  server.on("/toggle1", handleToggle1);
  server.on("/toggle2", handleToggle2);
  server.on("/toggle3", handleToggle3);
  server.on("/toggle4", handleToggle4);

  server.begin();
  Serial.println("Web server started!");
}

void loop() {
  server.handleClient();
  delay(2); // Allow CPU to switch tasks
}