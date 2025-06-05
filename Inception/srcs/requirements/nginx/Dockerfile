FROM debian:bullseye

# Installation des paquets nécessaires : nginx, openssl
RUN apt update && apt install -y \
    nginx \
    openssl \
    && apt clean && rm -rf /var/lib/apt/lists/*

# Création du dossier pour les certificats SSL
RUN mkdir -p /etc/nginx/ssl

# Génération d'un certificat auto-signé
RUN openssl req -x509 -nodes -days 365 \
    -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=FR/ST=42/L=Inception/O=42/CN=jotudela.42.fr"

# Copie de la configuration personnalisée de nginx
COPY ./conf/default.conf /etc/nginx/sites-available/default
RUN ln -sf /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default

# Exposer uniquement le port 443 (HTTPS)
EXPOSE 443

# Lancer nginx au démarrage du conteneur
CMD ["nginx", "-g", "daemon off;"]
