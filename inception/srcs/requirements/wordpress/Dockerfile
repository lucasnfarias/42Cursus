FROM debian:buster

LABEL author="Lucas Farias" user_name="lniehues" email="lniehues@student.42sp.org.br"

ARG HTTP_DIR=/var/www/html

ARG MYSQL_PASSWORD="marvin42"

ARG WP_DB_NAME=42_docker_wp
ARG WP_TAR=wordpress.tar.gz
ARG WP_TAR_URL=https://br.wordpress.org/latest-pt_BR.tar.gz

ARG PHPMYADMIN=phpmyadmin
ARG PHPMYADMIN_TAR=phpmyadmin.tar.gz
ARG PHPMYADMIN_TAR_URL=https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz

RUN apt-update && apt-get install php-gd php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli \
  php7.3-common php7.3-json php7.3-opcache php7.3-readline php-json php-mbstring php7.3-mbstring \
  php-curl php-gd php-intl php-soap php-xml php-xmlrpc php-zip -y ; \
  apt-get install wget -y ;

# Using web/working directory
WORKDIR $HTTP_DIR

# Installing Wordpress
RUN wget -P $HTTP_DIR -O $WP_TAR $WP_TAR_URL ; \
	tar xvf $WP_TAR ; \
	rm -rf $WP_TAR
COPY ./conf/wp-config.php wordpress/wp-config.php
RUN sed -i 's/%MYSQL_PASSWORD%/'$MYSQL_PASSWORD'/g' wordpress/wp-config.php ; \
	sed -i 's/%MYSQL_DB%/'$WP_DB_NAME'/g' wordpress/wp-config.php

# Installing PhpMyAdmin
RUN mkdir $HTTP_DIR/$PHPMYADMIN ; \
	wget -P $HTTP_DIR -O $PHPMYADMIN_TAR $PHPMYADMIN_TAR_URL ; \
	tar xvf $PHPMYADMIN_TAR ; \
	mv phpMyAdmin*/* phpmyadmin ; \
	rm -rf phpMyAdmin* $PHPMYADMIN_TAR
COPY ./conf/config.inc.php phpmyadmin

CMD service $(find /etc/init.d -name "php*" -printf "%f") start ;
