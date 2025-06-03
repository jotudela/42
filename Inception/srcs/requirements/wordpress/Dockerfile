FROM debian:bullseye

# Installer PHP + extensions
RUN apt update && apt install -y \
    lsb-release apt-transport-https ca-certificates wget gnupg \
 && wget -q https://packages.sury.org/php/apt.gpg -O- | apt-key add - \
 && echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" > /etc/apt/sources.list.d/php.list \
 && apt update && apt install -y \
    php8.2-fpm php8.2-mysql php8.2-curl php8.2-gd php8.2-mbstring \
    php8.2-xml php8.2-xmlrpc php8.2-soap php8.2-intl php8.2-zip \
    mariadb-client nginx curl unzip \
 && apt clean && rm -rf /var/lib/apt/lists/*

# Crée le dossier requis pour PHP-FPM
RUN mkdir -p /run/php

RUN sed -i 's|listen = .*|listen = 0.0.0.0:9000|' /etc/php/8.2/fpm/pool.d/www.conf

# Télécharger WordPress
RUN mkdir -p /var/www/html && \
    curl -o /tmp/latest.tar.gz https://wordpress.org/latest.tar.gz && \
    tar -xzf /tmp/latest.tar.gz -C /var/www/html --strip-components=1 && \
    rm /tmp/latest.tar.gz

# Permissions
RUN chown -R www-data:www-data /var/www/html

WORKDIR /var/www/html

EXPOSE 9000

# Lancer PHP-FPM
CMD ["php-fpm8.2", "-F"]