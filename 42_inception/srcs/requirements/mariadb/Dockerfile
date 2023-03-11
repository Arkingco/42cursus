FROM alpine:3.16

RUN apk update && \
    apk add mysql mysql-client

RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

RUN /etc/init.d/mariadb setup

RUN /etc/init.d/mariadb start
