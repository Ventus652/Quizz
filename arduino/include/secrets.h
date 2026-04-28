#pragma once

// =======================
// WiFi- und MQTT-Zugangsdaten
// =======================
// Hinweis: Zugangsdaten gehoeren normalerweise nicht ins Repository.
// Fuer den Kurs sind sie hier hinterlegt, sollten aber nicht weitergegeben werden.

static constexpr const char* WIFI_SSID     = "MQTT-Broker";
static constexpr const char* WIFI_PASSWORD = "Cannej-poscys-cyfqy9";

static constexpr const char* MQTT_HOST     = "iti-mqtt.mni.thm.de";
static constexpr uint16_t    MQTT_PORT     = 1883;
static constexpr const char* MQTT_USER     = "group-03";
static constexpr const char* MQTT_PASS     = "efKgxXw5dE.(";

// Topic-Praefix
static constexpr const char* MQTT_PREFIX    = "group-03/";
static constexpr const char* MQTT_TOPIC_MAC = "group-03/arduino/mac";
