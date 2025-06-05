#!/bin/bash
set -e

echo "=== DEBUT SETUP WORDPRESS ==="

# Créer /run/php si manquant
mkdir -p /run/php

# Vérifier si WordPress est déjà installé
if ! wp core is-installed --path=/var/www/html --allow-root 2>/dev/null; then
    echo "Installation de WordPress..."
    
    wp core install \
        --path=/var/www/html \
        --url="https://jotudela.42.fr" \
        --title="Mon Site WordPress" \
        --admin_user="${WP_ADMIN_USER:-admin}" \
        --admin_password="${WP_ADMIN_PASSWORD:-admin123}" \
        --admin_email="${WP_ADMIN_EMAIL:-admin@jotudela.42.fr}" \
        --locale=fr_FR \
        --allow-root

    # Téléchargement et activation de la langue
    wp language core install fr_FR --path=/var/www/html --allow-root
    wp language core activate fr_FR --path=/var/www/html --allow-root

    echo "WordPress installé avec succès !"
else
    echo "WordPress déjà installé."
fi

# Fixer les permissions
chown -R www-data:www-data /var/www/html

exec php-fpm8.2 -F