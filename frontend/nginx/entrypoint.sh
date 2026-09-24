#!/bin/sh
set -eu

cat <<EOF > /usr/share/nginx/html/env.js
window.__ENV__ = {
  MQTT_BROKER_URL:      "${MQTT_BROKER_URL:-localhost}",
  MQTT_BROKER_PORT:     "${MQTT_BROKER_PORT:-9001}",
  MQTT_USERNAME:        "${MQTT_USERNAME:-quiz-local}",
  MQTT_PASSWORD:        "${MQTT_PASSWORD:-change-me-mqtt}",
  MQTT_MESSAGE_PREFIX:  "${MQTT_MESSAGE_PREFIX:-quiz-local/}",
};
EOF

exec /docker-entrypoint.sh nginx -g 'daemon off;'
