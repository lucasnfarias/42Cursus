# Dockerfile must begin with FROM because it calls the Parent Image(exception: global args, docs and other can be put before FROM)
FROM debian:buster

LABEL author="Lucas Farias" user_name="lniehues" email="lniehues@student.42sp.org.br"

# Variables Configuration
ARG HTTP_DIR=/var/www/html
ARG NGINX_DIR=/etc/nginx
ARG NGINX_SITES_DIR=$NGINX_DIR/sites-enabled


# Used to re-synchronize the package index files from their sources.
RUN apt-get update

# Installing required programs nginx
RUN apt-get install nginx -y;

# Installing debug tools
RUN apt-get install curl zsh git vim -y;

# Using web/working directory
WORKDIR $HTTP_DIR

# Removing trash data
RUN rm -f $NGINX_DIR/default ; \
	rm -rf *

# Copying NGINX configuration files and preparing for PHP use
COPY ./conf/nginx_configuration $NGINX_SITES_DIR/default
RUN sed -i 's/%PHP_FPM%/'$(find /etc/init.d -name "php*" -printf "%f")'/g' $NGINX_SITES_DIR/default

# SSL Configuration

# OpenSSL Flags Explained:
#	#openssl: This is the basic command line tool for creating and managing OpenSSL certificates, keys, and other files.
#	#req: This subcommand specifies that we want to use X.509 certificate signing request (CSR) management. The “X.509” is a public
#	  key infrastructure standard that SSL and TLS adheres to for its key and certificate management.
#	#-x509: This further modifies the previous subcommand by telling the utility that we want to make a self-signed certificate
#	  instead of generating a certificate signing request, as would normally happen.
#	#-nodes: This tells OpenSSL to skip the option to secure our certificate with a passphrase. We need Nginx to be able to read
#	  the file, without user intervention, when the server starts up.
#	#-days 365: This option sets the length of time that the certificate will be considered valid. We set it for one year here.
#	#-newkey rsa:2048: This specifies that we want to generate a new certificate and a new key at the same time.The rsa:2048
#	  portion tells it to make an RSA key that is 2048 bits long.
#	#-keyout: This line tells OpenSSL where to place the generated private key file that we are creating.
#	#-out: This tells OpenSSL where to place the certificate that we are creating.

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/ssl/private/nginx-dev.key \
	-out /etc/ssl/certs/nginx-dev.crt \
	-subj "/C=BR/ST=Sao Paulo/L=Sao Paulo/O=42SP/OU=Development/CN=localhost"

#Checking and testing NGINX configuration
RUN cat $NGINX_SITES_DIR/default; \
	nginx -t

# Informing Docker the specified network ports to listen during a runtime by the container (HTTP /80 e SSL /443).
EXPOSE 80/tcp
EXPOSE 80/udp

EXPOSE 443/tcp
EXPOSE 443/udp

# When starting container, starting mysql, php proxy and nginx
CMD service nginx start; \
	sleep infinity
