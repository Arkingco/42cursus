# Use the Alpine base image
FROM alpine:latest

# https://wonit.tistory.com/335 ngix conf 파일 구조
# Install Nginx and some useful utilities
RUN apk add --update nginx curl bash

# Remove the default Nginx configuration file
RUN rm /etc/nginx/nginx.conf

# Copy the Nginx configuration file from the local directory
COPY nginx.conf /etc/nginx/

# Create a directory for the website files
RUN mkdir -p /var/www/html

# Copy the website files from the local directory
COPY index.html /var/www/html/

# Expose port 80 for HTTP traffic
EXPOSE 80

# Start Nginx when the container starts
CMD ["nginx", "-g", "daemon off;"]
