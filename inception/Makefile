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

VOLUME_DIR = /home/lniehues/data
WORDPRESS_VOLUME_DIR = $(VOLUME_DIR)/wordpress
MARIADB_VOLUME_DIR = $(VOLUME_DIR)/mysql
DOMAIN	=	$(shell awk '/lniehues.42.fr/{print $$2}' /etc/hosts)
VOLUMES = $(shell docker volume ls -q)
CONTAINERS = $(shell docker container ls -a -q)
HOSTS_BACKUP=srcs/requirements/tools/conf/hosts_backup

all: volumes hosts_setup
	cd srcs/ && docker-compose -f docker-compose.yml up --build -d

volumes: | $(MARIADB_VOLUME_DIR) $(WORDPRESS_VOLUME_DIR)

$(MARIADB_VOLUME_DIR):
	sudo mkdir -p $(MARIADB_VOLUME_DIR)
	docker volume create --name mariadb --opt type=none --opt device=$(MARIADB_VOLUME_DIR) --opt o=bind

$(WORDPRESS_VOLUME_DIR):
	sudo mkdir -p $(WORDPRESS_VOLUME_DIR)
	docker volume create --name wordpress --opt type=none --opt device=$(WORDPRESS_VOLUME_DIR) --opt o=bind

hosts_setup:
ifneq (${DOMAIN},lniehues.42.fr)
	cp /etc/hosts $(HOSTS_BACKUP)
	sudo rm /etc/hosts
	sudo cp ./srcs/requirements/tools/conf/hosts /etc/
endif

up:
	cd srcs/ && docker-compose -f docker-compose.yml up -d

down:
	cd srcs/ && docker-compose -f docker-compose.yml down

clean:
ifneq ($(CONTAINERS),)
	docker container rm $(CONTAINERS)
endif

ifneq ($(VOLUMES),)
	docker volume rm $(VOLUMES)
endif

fclean: clean
	sudo rm -rf /home/lniehues/data
	sudo rm /etc/hosts
	sudo cp $(HOSTS_BACKUP) /etc/hosts

re: fclean all

PHONY: all volumes clean fclean up down hosts_setup re
