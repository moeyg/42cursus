sed -i "s|#chroot_local_user=YES|chroot_local_user=YES|g"  /etc/vsftpd/vsftpd.conf
sed -i "s|#local_enable=YES|local_enable=YES|g"  /etc/vsftpd/vsftpd.conf
sed -i "s|#write_enable=YES|write_enable=YES|g"  /etc/vsftpd/vsftpd.conf
sed -i "s|#local_umask=022|local_umask=007|g"  /etc/vsftpd/vsftpd.conf

echo "allow_writeable_chroot=YES" >> /etc/vsftpd/vsftpd.conf
echo 'seccomp_sandbox=NO' >> /etc/vsftpd/vsftpd.conf
echo 'pasv_enable=YES' >> /etc/vsftpd/vsftpd.conf
echo "local_root=/var/www/wordpress" >> /etc/vsftpd/vsftpd.conf

sleep 5

chmod -R 777 /var/www/wordpress
chown -R ftpuser /var/www/wordpress
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf
