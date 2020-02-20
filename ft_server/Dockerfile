# Dockerfile must begin with FROM because it calls the Parent Image(exception: global args, docs and other can be put before FROM)
FROM debian:buster

LABEL author="Lucas Farias" user_name="lniehues" email="lniehues@student.42sp.org.br"

# Variables Configuration
ARG HTTP_DIR=/var/www/html
ARG NGINX_DIR=/etc/nginx
ARG NGINX_SITES_DIR=$NGINX_DIR/sites-enabled

ARG MYSQL_PASSWORD="lucasnfarias"

ARG WP_DB_NAME=42_docker_wp
ARG WP_TAR=wordpress.tar.gz
ARG WP_TAR_URL=https://br.wordpress.org/latest-pt_BR.tar.gz

ARG PHPMYADMIN=phpmyadmin
ARG PHPMYADMIN_TAR=phpmyadmin.tar.gz
ARG PHPMYADMIN_TAR_URL=https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz


# Used to re-synchronize the package index files from their sources.
RUN apt-get update

# Installing required programs nginx, php, mysql e wget(GNU Wget is a free software package for retrieving files
#using HTTP, HTTPS, FTP and FTPS the most widely-used Internet protocols.)
RUN apt-get install nginx -y; \
	apt-get install php-gd php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache \
	php7.3-readline php-json php-mbstring php7.3-mbstring php-curl php-gd php-intl php-soap php-xml php-xmlrpc php-zip -y ; \
	apt-get install default-mysql-server -y ; \
	apt-get install wget -y ;

# Installing debug tools
RUN apt-get install curl zsh git nano -y ; \
	yes | sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

# Using web/working directory
WORKDIR $HTTP_DIR

# Removing trash data
RUN rm -f $NGINX_DIR/default ; \
	rm -rf *

# Copying NGINX configuration files and preparing for PHP use
COPY ./srcs/nginx_configuration $NGINX_SITES_DIR/default
RUN sed -i 's/%PHP_FPM%/'$(find /etc/init.d -name "php*" -printf "%f")'/g' $NGINX_SITES_DIR/default

# SSL Configuration
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/ssl/private/nginx-dev.key \
	-out /etc/ssl/certs/nginx-dev.crt \
	-subj "/C=BR/ST=Sao Paulo/L=Sao Paulo/O=42SP/OU=Development/CN=localhost"

#Checking and testing NGINX configuration
RUN cat $NGINX_SITES_DIR/default ; \
	nginx -t

# Installing Wordpress
RUN wget -P $HTTP_DIR -O $WP_TAR $WP_TAR_URL ; \
	tar xvf $WP_TAR ; \
	rm -rf $WP_TAR
COPY ./srcs/wp-config.php wordpress/wp-config.php
RUN sed -i 's/%MYSQL_PASSWORD%/'$MYSQL_PASSWORD'/g' wordpress/wp-config.php ; \
	sed -i 's/%MYSQL_DB%/'$WP_DB_NAME'/g' wordpress/wp-config.php

# Installing PhpMyAdmin
RUN mkdir $HTTP_DIR/$PHPMYADMIN ; \
	wget -P $HTTP_DIR -O $PHPMYADMIN_TAR $PHPMYADMIN_TAR_URL ; \
	tar xvf $PHPMYADMIN_TAR ; \
	mv phpMyAdmin*/* phpmyadmin ; \
	rm -rf phpMyAdmin* $PHPMYADMIN_TAR
COPY ./srcs/config.inc.php phpmyadmin

# Starting MySQL, creating a table and setting my root mysql's password
RUN service mysql start ; \
	mysql -u root -p -e "CREATE DATABASE IF NOT EXISTS "$WP_DB_NAME";" ; \
	mysqladmin -u root -p password $MYSQL_PASSWORD

# Adding scripts like autoindex_switching
RUN mkdir scripts
COPY ./srcs/autoindex_switch.sh scripts/

# Informing Docker the specified network ports to listen during a runtime by the container (HTTP /80 e SSL /443).
EXPOSE 80/tcp
EXPOSE 80/udp

EXPOSE 443/tcp
EXPOSE 443/udp

# When starting container, starting mysql, php proxy and nginx
CMD service mysql start ; \
	service $(find /etc/init.d -name "php*" -printf "%f") start ; \
	service nginx start; \
	sleep infinity  

# OpenSSL Flags Explained:
#	#openssl: This is the basic command line tool for creating and managing OpenSSL certificates, keys, and other files.
#	#req: This subcommand specifies that we want to use X.509 certificate signing request (CSR) management. The “X.509” is a public 
#	key infrastructure standard that SSL and TLS adheres to for its key and certificate management. 
#	#-x509: This further modifies the previous subcommand by telling the utility that we want to make a self-signed certificate
#	instead of generating a certificate signing request, as would normally happen.
#	#-nodes: This tells OpenSSL to skip the option to secure our certificate with a passphrase. We need Nginx to be able to read
#	the file, without user intervention, when the server starts up. 
#	#-days 365: This option sets the length of time that the certificate will be considered valid. We set it for one year here.
#	#-newkey rsa:2048: This specifies that we want to generate a new certificate and a new key at the same time.The rsa:2048
#	portion tells it to make an RSA key that is 2048 bits long.
#	#-keyout: This line tells OpenSSL where to place the generated private key file that we are creating.
#	#-out: This tells OpenSSL where to place the certificate that we are creating.
