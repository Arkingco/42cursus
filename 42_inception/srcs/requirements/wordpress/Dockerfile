FROM alpine
EXPOSE 80
RUN apk update && \
    apk add nginx && \
    apk add php-fpm && \
    apk add php-mysqli

ADD config/default.conf /etc/nginx/http.d/default.conf
CMD ["/bin/sh", "-c", "/usr/sbin/php-fpm81; exec nginx -g 'daemon off;';"]
WORKDIR /var/www/localhost/htdoc

