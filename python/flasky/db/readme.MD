数据库笔记
sudo -u postgres -i 进入postgres账户
sudo -u postgres psql 进入psql
psql -h(host) 127.0.0.1 -p 5432 -U 用户名 -d 数据库名

在sudo -u postgres psql里面使用:
    alter user (username) with password '密码'; 可以更换账户密码

进入数据库步骤:
    sudo -u postgres -i
psql xv
\d　查看数据库的表
