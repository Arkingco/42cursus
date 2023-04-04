DOCKER_COMPOSE = docker-compose
DOCKER_COMPOSE_FILE = ./srcs/docker-compose.yml

all:
	mkdir -p ${HOME}/data/wordpress
	mkdir -p ${HOME}/data/mariadb
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) up --build -d 

down:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) down

up:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) up

clean:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) down --rmi all --volumes
	
fclean:
	make clean
	rm -rf ${HOME}/data

re:
	make fclean
	make all

.PHONY: all clean fclean re