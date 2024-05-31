

#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

//Provide the token generation process info.
#include <addons/TokenHelper.h>

//Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

#define WIFI_SSID "Pratz"
#define WIFI_PASSWORD "7975089407"

/* 2. Define the API Key */
#define API_KEY "AIzaSyDx0e5dVuvBOvbyZbdfDmHyn5TdgjTvDbc"

/* 3. Define the RTDB URL */
#define DATABASE_URL "wearable-acl-default-rtdb.firebaseio.com"         

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "pratyush252003@gmail.com"
#define USER_PASSWORD "pratyush#64"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(9600);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h


  Firebase.begin(&config, &auth);

  //Comment or pass false value when WiFi reconnection will control by your code or third party library
  Firebase.reconnectWiFi(true);

  Firebase.setDoubleDigits(5);

}

void loop() {
  
  int KneeAngle = 100;
  String SendKneeAngle = String(KneeAngle);

  Firebase.setString(fbdo, "KneeAngle", SendKneeAngle);
  delay(500);
  

}
