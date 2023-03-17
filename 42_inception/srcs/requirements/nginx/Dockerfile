FROM alpine
EXPOSE 80
RUN apk update && \
    apk add nginx && \
    apk add php-fpm && \
    apk add php-mysqli && \
    apk add curl

ADD config/default.conf /etc/nginx/http.d/default.conf
CMD ["/bin/sh", "-c", "exec nginx -g 'daemon off;';"]

