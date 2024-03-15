FROM alpine:3.16

ARG PHP_VERSION=8
 
RUN apk update && \
    apk add --no-cache \
    php${PHP_VERSION} \
    php${PHP_VERSION}-fpm \
    php${PHP_VERSION}-mysqli \
    php${PHP_VERSION}-json \
    php${PHP_VERSION}-curl \
    php${PHP_VERSION}-dom \
    php${PHP_VERSION}-exif \
    php${PHP_VERSION}-fileinfo \
    php${PHP_VERSION}-mbstring \
    php${PHP_VERSION}-openssl \
    php${PHP_VERSION}-xml \
    php${PHP_VERSION}-zip \
    php${PHP_VERSION}-redis \
    php${PHP_VERSION}-phar \
    curl \
    mariadb-client && \
    mkdir -p /var/www/wordpress && \
    curl -s -L https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar --output /usr/bin/wp && \
    chmod +x /usr/bin/wp && \
    wp core download --version=5.8.1 --path=/var/www/wordpress && \
    rm -f /var/cache/apk/* && \
    wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
    chmod +x /usr/bin/dumb-init

COPY ./requirements/wordpress/tools/script.sh /tmp
COPY ./requirements/wordpress/conf/wp-config.php /tmp

RUN chmod +x /tmp/script.sh

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD ["sh", "/tmp/script.sh"]
