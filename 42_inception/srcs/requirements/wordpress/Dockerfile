FROM alpine

RUN apk update && \
    apk add php-fpm && \
    apk add php-mysqli && \
    apk add curl

EXPOSE 9000

CMD ["/bin/sh", "-c", "/usr/sbin/php-fpm81 -F -R"]
WORKDIR /var/www/localhost/htdocs

