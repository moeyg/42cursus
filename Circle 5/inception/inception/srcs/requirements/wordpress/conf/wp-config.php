<?php
define( 'WP_REDIS_HOST', getenv('REDIS_HOST') );
define( 'WP_REDIS_PORT', getenv('REDIS_PORT') );
define( 'WP_REDIS_TIMEOUT', getenv('REDIS_TIMEOUT') );
define( 'WP_REDIS_READ_TIMEOUT', getenv('REDIS_READ_TIMEOUT') );
define( 'WP_REDIS_DATABASE', getenv('REDIS_DB') );
define( 'WP_CACHE', true );
define( 'DB_NAME', getenv('DB_NAME') );
define( 'DB_USER', getenv('DB_USER') );
define( 'DB_PASSWORD', getenv('DB_PASS') );
define( 'DB_HOST', getenv('DB_HOST') );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );

$table_prefix = 'wp_';

define( 'WP_DEBUG', false );

if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';

