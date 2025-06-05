FROM debian:bullseye

# --- PHP + extensions + dépendances ---
RUN apt update && apt install -y \
    lsb-release apt-transport-https ca-certificates wget gnupg curl unzip \
    procps \
    && wget -q https://packages.sury.org/php/apt.gpg -O- | apt-key add - \
    && echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" > /etc/apt/sources.list.d/php.list \
    && apt update && apt install -y \
    php8.2-fpm php8.2-mysql php8.2-curl php8.2-gd php8.2-mbstring \
    php8.2-xml php8.2-xmlrpc php8.2-soap php8.2-intl php8.2-zip \
    mariadb-client \
    && apt clean && rm -rf /var/lib/apt/lists/*

# --- Configuration PHP-FPM ---
RUN echo "env[WP_DB_NAME] = \$WP_DB_NAME\n\
env[WP_DB_USER] = \$WP_DB_USER\n\
env[WP_DB_PASSWORD] = \$WP_DB_PASSWORD\n\
env[WP_DB_HOST] = \$WP_DB_HOST\n\
env[WP_ADMIN_USER] = \$WP_ADMIN_USER\n\
env[WP_ADMIN_PASSWORD] = \$WP_ADMIN_PASSWORD\n\
env[WP_ADMIN_EMAIL] = \$WP_ADMIN_EMAIL" >> /etc/php/8.2/fpm/pool.d/www.conf

# --- PHP-FPM listen port ---
RUN sed -i 's|listen = .*|listen = 9000|' /etc/php/8.2/fpm/pool.d/www.conf

# --- Installer wp-cli ---
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

# --- Télécharger WordPress ---
RUN mkdir -p /var/www/html && \
    curl -o /tmp/latest.tar.gz https://wordpress.org/latest.tar.gz && \
    tar -xzf /tmp/latest.tar.gz -C /var/www/html --strip-components=1 && \
    rm /tmp/latest.tar.gz

# --- Copier la configuration ---
COPY conf/wp-config.php /var/www/html/wp-config.php

# --- Script de setup ---
COPY ./tools/setup.sh /setup.sh
RUN chmod +x /setup.sh

# --- Permissions ---
RUN chown -R www-data:www-data /var/www/html

WORKDIR /var/www/html
EXPOSE 9000

CMD ["/setup.sh"]