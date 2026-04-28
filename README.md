







# QuizArena — Multiplayer Trivia Quiz (Group 03)

**Informatics Project — Winter Semester 2025/2026**

**Group 03:** Junior Kana · Priscille C. Moumani

This is our implementation of the Multiplayer Trivia Quiz project. Players join a shared lobby, pick a hardware or web controller, and compete in real-time quiz rounds. The game supports up to 5 human players plus optional bots, RFID-based login via the ESP32 hardware controller, and per-mode highscores (Q5 / Q10 / Q20).

The backend is written in Java with Vert.x and communicates with both a REST-based frontend and all controllers via MQTT. The frontend and a separate web controller are served as static sites through NGINX. Everything runs in Docker.

## Project Introduction

- [EN](./doc/ProjectDescription.md)
- [DE](./doc/ProjektBeschreibung.md)

## Design Proposal

- [EN](./doc/DesignProposal.md)
- [DE](./doc/DesignVorschlag.md)

## Documentation

Detailed documentation for the project is available in the [`docs/`](./docs/README.md) folder:

- [Architecture](./docs/architecture.md) — component diagram and game flow
- [HTTP API](./docs/http-api.md) — all REST routes with request/response examples
- [MQTT Topics](./docs/mqtt-topics.md) — all topics, payloads, publisher/subscriber
- [Database](./docs/database.md) — full schema with field types and relationships
- [Deployment](./docs/deployment.md) — Docker setup, ports, local multiplayer testing

## Table of Contents

- [QuizArena — Multiplayer Trivia Quiz (Group 03)](#quizarena--multiplayer-trivia-quiz-group-03)
  - [Project Introduction](#project-introduction)
  - [Design Proposal](#design-proposal)
  - [Documentation](#documentation)
  - [Table of Contents](#table-of-contents)
  - [Technologies Used](#technologies-used)
  - [Component-Architecture](#component-architecture)
  - [Setup Instructions](#setup-instructions)
    - [Prerequisites](#prerequisites)
      - [Use a linux based OS](#use-a-linux-based-os)
      - [Install Docker](#install-docker)
      - [Add an SSH-Key to GitLab](#add-an-ssh-key-to-gitlab)
    - [Clone the Repository](#clone-the-repository)
    - [Environment Variables](#environment-variables)
    - [Build and Run the Project](#build-and-run-the-project)
    - [Stop the Project](#stop-the-project)
    - [Accessing the Application](#accessing-the-application)
  - [Detailed Explanation](#detailed-explanation)
  - [Troubleshooting](#troubleshooting)

## Technologies Used

- **Java**: Programming language for the backend.
- **Vert.x**: Toolkit for building reactive applications on the JVM.
- **MariaDB**: Relational database management system.
- **Docker**: Platform for developing, shipping, and running applications in containers.
- **MQTT**: Lightweight messaging protocol for small sensors and mobile devices.
- **Bootstrap**: CSS framework for developing responsive and mobile-first websites.
- **Arduino Uno**/**ESP32**: Low-cost, low-power system on a chip microcontroller with integrated Wi-Fi and dual-mode Bluetooth.

## Component-Architecture

<img src="doc/comp_arch.png" width="1000px">

## Setup Instructions

### Prerequisites

#### Use a linux based OS

Either install a separate linux distro as a dual-boot (preferably Ubuntu, see [here for more information](https://wiki.ubuntuusers.de/Dualboot/)),
or try your luck with [Windows WSL](https://learn.microsoft.com/en-us/windows/wsl/install) feature.

> **WARNING**: We can and will only strongly support native / dual-boot installations of Ubuntu.

#### Install Docker

Follow the instructions for your operating system found [here](https://docs.docker.com/desktop/).

#### Add an SSH-Key to GitLab

To authenticate against our GitLab-Instance, please follow the instructions found [here](https://git.thm.de/help/user/ssh).

### Clone the Repository

1. Open a terminal or command prompt.
2. Clone the repository:

   ```bash
   git clone <YourGitlabProject-URL>
   cd <TheCreatedFolder>
   ```

### Environment Variables

In `.env` file you will find the environment variables used in this project. Change the file in the root directory if needed. Default settings are:

```
MQTT_USERNAME=your_mqtt_username
MQTT_PASSWORD=your_mqtt_password
DB_USER=user
DB_PASSWORD=userpassword
DB_ROOT_PASSWORD=rootpassword
DB_NAME=game
DB_HOST=mariadb
DB_PORT=3306
```

### Build and Run the Project

Run `docker compose up --build --watch` whilst in the root directory of this repository.

This command will:

1. Build and start the MariaDB database and phpMyAdmin tool.
2. Build and start the Mosquitto MQTT broker.
3. Build and start the Java backend.
4. Start NGINX and serve the frontend.

If all went fine, you should see prints similar to these:

```
...
✔ Network game-network      Created
✔ Container mosquitto       Created
✔ Container frontend        Created
✔ Container mariadb         Created
✔ Container web-controller  Created
✔ Container phpmyadmin      Created
✔ Container java-backend    Created
```


And the `docker ps` command should list every running container, similar to:

```
...   IMAGE                          ...    STATUS                  ...       NAMES
...   mariadb:latest                 ...    Up About a minute ago   ...       mariadb
...   eclipse-mosquitto:latest       ...    Up About a minute ago   ...       mosquitto
...   phpmyadmin:latest              ...    Up About a minute ago   ...       phpmyadmin
...   java-backend:latest            ...    Up About a minute ago   ...       java-backend
...   nginx:latest                   ...    Up About a minute ago   ...       frontend
...   nginx:latest                   ...    Up About a minute ago   ...       web-controller
```

### Stop the Project

To simply hold execution run `docker compose down` while.
To clean everything you did, run `docker system prune -a --volumes --force`.

> **WARNING**: Keep in mind that `docker system prune` will erase everything you did in docker.

### Accessing the Application

| Service        | Port            | URL                   |
|----------------|-----------------|-----------------------|
| Frontend       | `80` / `443`    | http://localhost      |
| Web-Controller | `81` / `444`    | http://localhost:81   |
| phpMyAdmin     | `8081`          | http://localhost:8081 |
| Backend        | `8080`          | http://localhost:8080 |
| MariaDB        | `3306`          | --- n/a ---           |
| MOSQUITTO      | `1883` / `9001` | --- n/a ---           |


## [Detailed Explanation](./doc/Explanation.md)

## Troubleshooting

- **Database Connection Issues**: Ensure that the database service is running and the environment variables are correctly set.
- **MQTT Connection Issues**: Ensure that the MQTT broker service is running and the credentials are correctly set. Ensure your firewall not blocking MQTT.
- **Build Issues**: Ensure that you have the correct versions of Docker and Docker Compose installed.

