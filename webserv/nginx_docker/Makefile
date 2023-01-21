# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 18:58:50 by lniehues          #+#    #+#              #
#    Updated: 2023/01/21 20:13:47 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

IMAGE		:=	nginx
CONTAINER	:=	nginx

build:
	docker build -t $(IMAGE) .

build_no_cache:
	docker build --no-cache=true -t $(IMAGE) .

run:
	docker run -d --rm -p 4242:4242 --name $(CONTAINER) -v "/home/lniehues/projects/42Cursus/webserv/nginx_docker/srcs:/var/www/example" $(IMAGE)

exec_bash:
	docker exec -it $(CONTAINER) /bin/bash

stop:
	docker stop $(CONTAINER)

.PHONY:	build run exec stop
