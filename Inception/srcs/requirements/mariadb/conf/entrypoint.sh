#!/bin/bash
set -e

# Assure que bind-address est sur 0.0.0.0 au démarrage (redondant, sécurité)
sed -i "s/^bind-address\s*=.*/bind-address = 0.0.0.0/" /etc/mysql/mariadb.conf.d/50-server.cnf

envsubst < /docker-entrypoint-initdb.d/init.sql.template > /tmp/init.sql
echo "===== Script SQL généré ====="
cat /tmp/init.sql
echo "============================="

# Lance MariaDB en arrière-plan (sans réseau pour l'init)
mysqld_safe --skip-networking &
pid="$!"

echo "⏳ Attente de MariaDB..."
until mysqladmin ping --silent; do
  echo "Waiting for database to be ready..."
  sleep 2
done

echo "🚀 Exécution du script SQL d'init"
if command -v mariadb >/dev/null 2>&1; then
    mariadb < /tmp/init.sql
else
    mysql < /tmp/init.sql
fi

echo "🛑 Arrêt du serveur temporaire"
mysqladmin shutdown

echo "✅ Démarrage final de MariaDB"
exec mysqld_safe