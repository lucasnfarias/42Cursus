FROM		debian:buster

ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG MYSQL_ROOT_PASSWORD
ARG DATABASE_PATH=/var/lib/mysql/$MYSQL_DATABASE

RUN		apt-get update && apt-get install -y apt-utils mariadb-server procps \
  && mkdir -p /var/run/mysqld \
  && chown -R mysql:mysql /var/run/mysqld

COPY		./conf/wordpress_default.sql /

RUN   service mysql start; \
  mysql -u root --execute="CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE; \
  CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'; \
  ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; \
  GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';"; \
  mysql -uroot -p$MYSQL_ROOT_PASSWORD $MYSQL_DATABASE < wordpress_default.sql ; \
  mysqladmin -uroot -p$MYSQL_ROOT_PASSWORD shutdown;

EXPOSE	3306

CMD			["mysqld", "--bind-address=0.0.0.0"]
