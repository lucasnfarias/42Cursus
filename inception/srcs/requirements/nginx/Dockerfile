# Dockerfile must begin with FROM because it calls the Parent Image(exception: global args, docs and other can be put before FROM)
FROM debian:buster

LABEL author="Lucas Farias" user_name="lniehues" email="lniehues@student.42sp.org.br"

# Variables Configuration (those with no values get their values from .env/docker-compose.yml)
ARG DOMAIN_NAME
ARG NGINX_ROOT
ARG CERTS_
ARG CERT_KEY_
ARG HTTP_DIR=/var/www/lniehues
ARG NGINX_DIR=/etc/nginx
ARG NGINX_SITES_ENABLED=$NGINX_DIR/sites-enabled
ARG NGINX_SITES_AVAILABLE=$NGINX_DIR/sites-available

WORKDIR /

# Used to re-synchronize the package index files from their sources.
RUN apt-get update && apt-get install -y nginx curl vim openssl;

# Copying NGINX configuration files and preparing for PHP use
COPY ./conf/ /srcs/

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

RUN openssl req -x509 -nodes -days 365 -newkey rsa:4096  \
	-out $CERTS_ \
	-keyout $CERT_KEY_ \
	-subj "/C=BR/ST=Sao Paulo/L=Sao Paulo/O=42SP/OU=Development/CN=$DOMAIN_NAME"

RUN mkdir -p $HTTP_DIR; mv /srcs/nginx_config $NGINX_SITES_AVAILABLE/nginx_config; \
  sed -i "s/DOMAIN_NAME/$DOMAIN_NAME/g" $NGINX_SITES_AVAILABLE/nginx_config; \
  sed -i -r "s#NGINX_ROOT#$NGINX_ROOT#g" $NGINX_SITES_AVAILABLE/nginx_config; \
	sed -i -r "s#CERTS_#$CERTS_#" $NGINX_SITES_AVAILABLE/nginx_config; \
	sed -i -r "s#CERT_KEY_#$CERT_KEY_#" $NGINX_SITES_AVAILABLE/nginx_config; \
	ln -s $NGINX_SITES_AVAILABLE/nginx_config etc/nginx/sites-enabled/;

EXPOSE 443/tcp
EXPOSE 443/udp

# starting nginx
CMD ["nginx", "-g", "daemon off;"]
