<?php

// Définir les variables utilisées par WordPress
define('DB_NAME', getenv('WP_DB_NAME') ?: 'wordpress');
define('DB_USER', getenv('WP_DB_USER') ?: 'root');
define('DB_PASSWORD', getenv('WP_DB_PASSWORD') ?: '');
define('DB_HOST', getenv('WP_DB_HOST') ?: 'localhost');
define('WPLANG', 'fr_FR');
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

// Préfixe des tables
$table_prefix = 'wp_';

// Désactiver le debug WordPress (prod)
define('WP_DEBUG', false);

// Clés de sécurité générées automatiquement
define('AUTH_KEY',         'mettez-ici-une-phrase-unique-de-votre-choix');
define('SECURE_AUTH_KEY',  'mettez-ici-une-phrase-unique-de-votre-choix');
define('LOGGED_IN_KEY',    'mettez-ici-une-phrase-unique-de-votre-choix');
define('NONCE_KEY',        'mettez-ici-une-phrase-unique-de-votre-choix');
define('AUTH_SALT',        'mettez-ici-une-phrase-unique-de-votre-choix');
define('SECURE_AUTH_SALT', 'mettez-ici-une-phrase-unique-de-votre-choix');
define('LOGGED_IN_SALT',   'mettez-ici-une-phrase-unique-de-votre-choix');
define('NONCE_SALT',       'mettez-ici-une-phrase-unique-de-votre-choix');

// Configuration URLs
define('WP_HOME', 'https://jotudela.42.fr');
define('WP_SITEURL', 'https://jotudela.42.fr');

// Configuration des uploads et permissions
define('FS_METHOD', 'direct');

// Dossier de base WordPress
if (!defined('ABSPATH')) {
    define('ABSPATH', __DIR__ . '/');
}

// Lancer WordPress
require_once ABSPATH . 'wp-settings.php';