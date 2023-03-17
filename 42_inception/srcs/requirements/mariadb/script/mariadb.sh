mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql

# /usr/bin/mysqld --user=mysql << EOF
# USE mysql;
# EOF

exec /usr/bin/mysqld --user=mysql --console
