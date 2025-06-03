FROM debian:bullseye

RUN apt update && apt install -y mariadb-server gettext && \
    apt clean && rm -rf /var/lib/apt/lists/*

# Remplace bind-address dans la config MariaDB pour écouter sur 0.0.0.0
RUN sed -i "s/^bind-address\s*=.*/bind-address = 0.0.0.0/" /etc/mysql/mariadb.conf.d/50-server.cnf

COPY conf/init.sql.template /docker-entrypoint-initdb.d/init.sql.template
COPY conf/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

VOLUME ["/var/lib/mysql"]
EXPOSE 3306

CMD ["/entrypoint.sh"]