# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 20:58:33 by lniehues          #+#    #+#              #
#    Updated: 2022/10/31 23:05:55 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VOLUME_DIR = /home/lniehues/data/
WORDPRESS_VOLUME_DIR = $(VOLUME_DIR)wordpress
MARIADB_VOLUME_DIR = $(VOLUME_DIR)mysql
DOMAIN	=	$(shell awk '/lniehues.42.fr/{print $$2}' /etc/hosts)
VOLUMES = $(shell docker volume ls -q)

all:
	cd srcs/ && docker-compose -f docker-compose.yml up --build -d

# | dir and not file (if exists and not timestamp)
# volumes: | $(MARIADB_VOLUME_DIR) $(WORDPRESS_VOLUME_DIR)

# $(MARIADB_VOLUME_DIR):
# 	sudo mkdir -p $(MARIADB_VOLUME_DIR)
# 	docker volume create --name dbdata --opt type=none --opt device=$(MARIADB_VOLUME_DIR) --opt o=bind

# $(WORDPRESS_VOLUME_DIR):
# 	sudo mkdir -p $(WORDPRESS_VOLUME_DIR)
# 	docker volume create --name wordpress --opt type=none --opt device=$(WORDPRESS_VOLUME_DIR) --opt o=bind

# hosts:
# ifneq (${DOMAIN},lniehues.42.fr)
# 	cp /etc/hosts ./hosts_backup
# 	sudo rm /etc/hosts
# 	sudo cp ./srcs/requirements/tools/hosts /etc/
# endif

up:
	cd srcs/ && docker-compose -f docker-compose.yml up -d

down:
	cd srcs/ && docker-compose -f docker-compose.yml down

clean:
ifneq ($(VOLUMES),)
	docker volume rm $(VOLUMES)
endif

# fclean: clean
# 	sudo rm -rf /home/lniehues/data
# 	sudo rm /etc/hosts
# 	sudo mv ./hosts_backup /etc/hosts
# 	docker system prune -a --volumes
