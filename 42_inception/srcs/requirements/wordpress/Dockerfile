FROM alpine

RUN apk update && \
    apk add php-fpm && \
    apk add php-mysqli && \
    apk add curl iputils

EXPOSE 9000

ADD config/www.conf /etc/php81/php-fpm.d/www.conf
ADD config/wp-config.php /tmp/wp-config.php
ADD script/wordpress.sh /tmp/wordpress.sh

CMD ["/bin/sh", "/tmp/wordpress.sh"]

WORKDIR /var/www/localhost/htdocs

