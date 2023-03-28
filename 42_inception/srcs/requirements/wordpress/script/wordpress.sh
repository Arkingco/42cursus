wp core download --allow-root --path=/var/www/html

               
wp	core install \
	--allow-root \
	--path=/var/www/html \
	--url="kipark.42.fr" \
	--title=Inception \
    --admin_user=your_admin_username="kipark" \
    --admin_password="1234" \
    --admin_email=your_admin_email="arkingco@gmail.com" \
	--skip-email

/usr/sbin/php-fpm8 -F -R