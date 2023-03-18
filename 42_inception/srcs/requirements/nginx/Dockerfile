FROM alpine
EXPOSE 80
RUN apk update && \
    apk add nginx && \
    apk add curl iputils

ADD config/default.conf /etc/nginx/http.d/default.conf
CMD ["/bin/sh", "-c", "exec nginx -g 'daemon off;';"]

