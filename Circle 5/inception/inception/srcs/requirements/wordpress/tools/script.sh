# !/bin/bash

sed -i "s/.*listen = 127.0.0.1.*/listen = 9000/g" /etc/php8/php-fpm.d/www.conf
echo "env[DB_HOST] = \$DB_HOST" >> /etc/php8/php-fpm.d/www.conf
echo "env[DB_USER] = \$DB_USER" >> /etc/php8/php-fpm.d/www.conf
echo "env[DB_PASS] = \$DB_PASS" >> /etc/php8/php-fpm.d/www.conf
echo "env[DB_NAME] = \$DB_NAME" >> /etc/php8/php-fpm.d/www.conf

if [ ! -f "/var/www/wordpress/wp-config.php" ]; then
  cp /tmp/wp-config.php /var/www/wordpress/wp-config.php
  sleep 5
  if ! mysqladmin -h $DB_HOST -u $DB_USER --password=$DB_PASS --wait=60 ping > /dev/null; then
    printf "MariaDB Error\n"
    exit 1
  fi
  wp core install --url="$DOMAIN_NAME" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USR" --admin_password="$WP_ADMIN_PWD" --admin_email="$WP_ADMIN_EMAIL" --skip-email --path=/var/www/wordpress
  wp plugin install redis-cache --activate --path=/var/www/wordpress
  wp plugin update --all --path=/var/www/wordpress
  wp user create $WP_USR $WP_USR_EMAIL --role=author --user_pass=$WP_USR_PWD --path=/var/www/wordpress
  wp redis enable --path=/var/www/wordpress
fi

/usr/sbin/php-fpm8 -F
