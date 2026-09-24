# QuizArena - Real-Time Multiplayer Quiz Platform

QuizArena is a full-stack academic team project that combines a Java backend, a relational database, browser clients and an ESP32 hardware controller in one real-time multiplayer quiz system.

Players join a shared lobby, choose a web or hardware controller and compete in timed quiz rounds. The platform supports up to five human players, optional bots, RFID login and separate high-score modes.

## Why this project matters

This project demonstrates more than a single web interface. It connects several independently deployed components through REST and MQTT, persists game data in MariaDB and provides a reproducible Docker Compose environment.

### Key features

- Multiplayer lobby and game-session management
- JWT-based authentication and bcrypt password hashing
- Real-time communication through MQTT
- REST API for users, lobbies, games and scores
- MariaDB persistence with relational data modelling
- Web frontend and separate mobile-friendly controller
- ESP32 controller with RFID-based login
- Multiple game lengths, bots and high-score tracking
- Docker Compose setup for the complete platform

## My contribution

QuizArena was developed as a two-person university team project. My documented contribution includes:

- web- and backend-oriented application development;
- relational data modelling, SQL queries and MariaDB integration;
- communication between application components;
- structured collaboration with Git;
- software testing, error analysis and technical documentation.

## Architecture

![QuizArena component architecture](doc/comp_arch.png)

| Component | Technology | Responsibility |
| --- | --- | --- |
| Backend | Java 21, Vert.x | REST endpoints, game logic, authentication and MQTT coordination |
| Database | MariaDB | Users, questions, sessions and high scores |
| Frontend | HTML, CSS, JavaScript, Bootstrap | Main game interface |
| Web controller | HTML, CSS, JavaScript | Player input from a phone or browser |
| Hardware controller | ESP32, Arduino, RFID | Physical player authentication and answers |
| Messaging | Mosquitto MQTT | Real-time events between services and controllers |
| Deployment | Docker Compose, NGINX | Reproducible local environment |

## Quick start

### Prerequisites

- Docker with Docker Compose
- Git
- A Linux environment or Windows with WSL2

### 1. Clone and configure

~~~bash
git clone https://github.com/Ventus652/Quizz.git
cd Quizz
cp .env.example .env
~~~

Replace the development placeholders in `.env` before starting the services.

For the ESP32 controller:

~~~bash
cp arduino/include/secrets.example.h arduino/include/secrets.h
~~~

Then configure the local Wi-Fi and MQTT values in `secrets.h`.

### 2. Start the platform

~~~bash
docker compose up --build
~~~

### 3. Open the services

| Service | Local URL / port |
| --- | --- |
| Frontend | `http://localhost` |
| Web controller | `http://localhost:81` |
| Backend API | `http://localhost:8080` |
| phpMyAdmin | `http://localhost:8081` |
| MariaDB | `localhost:3306` |
| MQTT | `localhost:1883` / WebSocket `9001` |

Stop the environment with:

~~~bash
docker compose down
~~~

Use `docker compose down --volumes` only when you intentionally want to remove the local database volume.

## Documentation

- [Project introduction](doc/ProjectDescription.md)
- [Architecture and game flow](docs/architecture.md)
- [HTTP API](docs/http-api.md)
- [MQTT topics](docs/mqtt-topics.md)
- [Database model](docs/database.md)
- [Deployment guide](docs/deployment.md)
- [Arduino wiring](doc/arduino_wiring.png)

## Security notes

- Real credentials are not stored in the repository.
- `.env`, generated browser configuration files and `arduino/include/secrets.h` are ignored by Git.
- The committed example values are intended only for local development.
- MQTT credentials used by browser clients should be limited to a dedicated local broker account and must not be reused elsewhere.

## Project context

University project, winter semester 2025/2026. Developed by Junior Kana and Priscille C. Moumani.

## Author

[Junior Kana](https://github.com/Ventus652) - Computer Science student interested in software development and data-driven applications.
