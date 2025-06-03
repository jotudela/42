# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 11:12:15 by jojo              #+#    #+#              #
#    Updated: 2025/06/03 15:13:19 by jojo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                             DOCKER INCEPTION MAKEFILE                        #
# **************************************************************************** #

LOGIN := jotudela
DATA_DIR := /home/$(LOGIN)/data
NETWORK := inception
COMPOSE_FILE := srcs/docker-compose.yml
COMPOSE := docker compose -f $(COMPOSE_FILE)

all: setup build up backup

# ------------------------------
# Setup local folders and network
# ------------------------------
setup:
	@echo "🔧 Création des dossiers de volumes..."
	@mkdir -p $(DATA_DIR)/mariadb
	@mkdir -p $(DATA_DIR)/wordpress
	@echo "🔗 Création du réseau Docker ($(NETWORK)) si non existant..."
	@docker network inspect $(NETWORK) >/dev/null 2>&1 || docker network create $(NETWORK)

# ------------------------------
# Docker Compose build & run
# ------------------------------
build:
	@echo "🐳 Build des images avec tag :42"
	@$(COMPOSE) build

up:
	@echo "🚀 Lancement des services..."
	@$(COMPOSE) up -d

down:
	@echo "🛑 Arrêt et suppression des containers..."
	@$(COMPOSE) down

fclean: down
	@echo "🔥 Suppression des images et des volumes..."
	@docker rmi mariadb:42 wordpress:42 nginx:42 || true
	@docker volume rm srcs_mariadb_volume srcs_wordpress_volume || true
	@rm -rf $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress


re: fclean all

# ------------------------------
# Backup & Restore volumes
# ------------------------------
backup: backup-mariadb backup-wordpress

backup-mariadb:
	docker exec mariadb tar cf - -C /var/lib/mysql . | tar xf - -C $(DATA_DIR)/mariadb

backup-wordpress:
	docker exec wordpress tar cf - -C /var/www/html . | tar xf - -C $(DATA_DIR)/wordpress
	
.PHONY: all setup build up down fclean re backup backup-mariadb backup-wordpress