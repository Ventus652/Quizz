#pragma once

// Copy this file to secrets.h and replace the development placeholders.
// Never commit secrets.h.

static constexpr const char* WIFI_SSID     = "your-wifi-ssid";
static constexpr const char* WIFI_PASSWORD = "your-wifi-password";

static constexpr const char* MQTT_HOST     = "192.0.2.1";
static constexpr uint16_t    MQTT_PORT     = 1883;
static constexpr const char* MQTT_USER     = "quiz-local";
static constexpr const char* MQTT_PASS     = "change-me-mqtt";

static constexpr const char* MQTT_PREFIX    = "quiz-local/";
static constexpr const char* MQTT_TOPIC_MAC = "quiz-local/mac";
