# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 20:58:33 by lniehues-a          #+#    #+#              #
#    Updated: 2022/10/31 23:05:48 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VOLUME_DIR = /home/lniehues/data/
WORDPRESS_VOLUME_DIR = $(VOLUME_DIR)wordpress
MARIADB_VOLUME_DIR = $(VOLUME_DIR)mysql
DOMAIN	=	$(shell awk '/lniehues.42.fr/{print $$2}' /etc/hosts)
VOLUMES = $(shell docker volume ls -q)

all: volumes hosts
	cd srcs/ && docker-compose -f docker-compose.yml up --build -d

volumes: | $(MARIADB_VOLUME_DIR) $(WORDPRESS_VOLUME_DIR)

$(MARIADB_VOLUME_DIR):
	sudo mkdir -p $(MARIADB_VOLUME_DIR)
	docker volume create --name dbdata -o type=none -o device=$(MARIADB_VOLUME_DIR) -o o=bind

$(WORDPRESS_VOLUME_DIR):
	sudo mkdir -p $(WORDPRESS_VOLUME_DIR)
	docker volume create --name wordpress -o type=none -o device=$(WORDPRESS_VOLUME_DIR) -o o=bind

hosts:
ifneq (${DOMAIN},lniehues.42.fr)
	cp /etc/hosts ./hosts_backup
	sudo rm /etc/hosts
	sudo cp ./srcs/requirements/tools/conf/hosts /etc/
endif

up:
	cd srcs/ && docker-compose -f docker-compose.yml up

down:
	cd srcs/ && docker-compose -f docker-compose.yml down

clean:
ifneq ($(VOLUMES),)
	docker volume rm $(VOLUMES)
endif

fclean: clean
	sudo rm -rf /home/lniehues/data
	sudo rm /etc/hosts
	sudo mv ./hosts_backup /etc/hosts
	docker system prune -a --volumes

PHONY: all volumes clean fclean up down hosts
