FROM alpine:3.16

RUN apk update && \
    apk add openrc && \
    apk add mysql mysql-client

# openrc 실행을 위한 softlevel 파일 생성
COPY ./config/softlevel /run/openrc/softlevel

# RUN /etc/init.d/mariadb setup
# RUN /etc/init.d/mariadb start

