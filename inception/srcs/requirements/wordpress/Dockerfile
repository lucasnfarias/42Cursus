FROM debian:buster

ARG HTTP_DIR=/var/www/lniehues
ARG WP_TAR_URL=https://wordpress.org/latest.tar.gz
ARG WP_TAR=wordpress-latest.tar.gz
ARG WP_CONFIG=wp-config.php
ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG MYSQL_HOST
ARG MYSQL_DATABASE

RUN apt-get update && apt-get install \
	wget php7.3 php7.3-fpm php7.3-opcache php7.3-cli \
	php7.3-gd php7.3-curl php7.3-mysql php7.3-mbstring -y;

RUN mkdir /run/php && \
	mkdir -p $HTTP_DIR && \
	wget $WP_TAR_URL -O $WP_TAR && \
	tar -xzvf $WP_TAR && \
	rm $WP_TAR && \
	mv wordpress $HTTP_DIR/wordpress

COPY conf/ /srcs/

RUN cp /srcs/www.conf /etc/php/7.3/fpm/pool.d/

WORKDIR $HTTP_DIR/wordpress

RUN mv wp-config-sample.php $WP_CONFIG; \
	sed -i "s/username_here/$MYSQL_USER/g" $WP_CONFIG; \
	sed -i "s/password_here/$MYSQL_PASSWORD/g" $WP_CONFIG; \
	sed -i "s/localhost/$MYSQL_HOST/g" $WP_CONFIG; \
	sed -i "s/database_name_here/$MYSQL_DATABASE/g" $WP_CONFIG;

EXPOSE 9000

ENTRYPOINT ["/usr/sbin/php-fpm7.3", "--nodaemonize"]
