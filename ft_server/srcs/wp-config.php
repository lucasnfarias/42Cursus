<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */
// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', '%MYSQL_DB%' );
/** MySQL database username */
define( 'DB_USER', 'root' );
/** MySQL database password */
define( 'DB_PASSWORD', '%MYSQL_PASSWORD%' );
/** MySQL hostname */
define( 'DB_HOST', 'localhost' );
/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );
/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );
/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'g5xzAR}yN`e$G$ZEzh5*W$t^cvt*z>vY]151b;n~Lk(83c;v$pBCbPB)vfts_!=:');
define('SECURE_AUTH_KEY',  '? =catZA)%2ruS+GFZ$32o+VwTL8sF(>}%$SAnOM?H~oU<af|I`o8^|Yxo~zfjT&');
define('LOGGED_IN_KEY',    '^(:H(_e&Lfd B@(`+O^6!v8]eQ@rm]xQF{,bI4_}.]icFYi Xwuu L/.|:$6Cn2y');
define('NONCE_KEY',        '1O{|+X@-^eZ~iH $kekH#i[}zT4G:+~sbVRH6aHy~[axHf87uD<Q,+B.T.Td|+QK');
define('AUTH_SALT',        'Iw e?ri+|pcI/y5)Rr;`YGM/F/k+(~i~B`wcPb)hMn;vp~|qEUEY:%7^(=jKbeN/');
define('SECURE_AUTH_SALT', '`fj;@wCN3Dfo+hRX4Uu6uVPs889qG?$PFbm+P$n#n&Q<QK9?@8}6yo#-Rg@(%)8k');
define('LOGGED_IN_SALT',   ',sJWjZ%sjX?iC$y)HBdfE7;+<SO%{g, [C_XaT=~_=.]z{K#>0CJ^izDpdCpwa(~');
define('NONCE_SALT',       'd]iAbw5-G 22q%gP&3ETw )Ay~tc<wEP:Pi{I9R(E6o9oaxGSD0&L1|b_*x(=laX');
/**#@-*/
/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';
/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );
/* That's all, stop editing! Happy publishing. */
/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}
/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
